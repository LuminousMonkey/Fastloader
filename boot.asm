#import "c64-memory-locations.asm"

.const TARGET = $0400
.const TRACK = 18
.const DATA_OUT = %00100000       // Bit 5
.const CLOCK_OUT = %00010000      // Bit 4
.const VIC_OUT = %00000011        // Bits need to be on to keep VIC happy.

.var seccnt = 2

// C64 Memory Locations
.const SEC_ADDR_FILE = $b9
.const LOG_NUM_FILE = $b8

* = $0188 "Load Address"
main:
  lda #$0f
  sta SEC_ADDR_FILE             // Secondary address of current file.
  sta LOG_NUM_FILE              // Logical number of current file.
  ldx #<memory_execute
  ldy #>memory_execute
  lda #memory_execute_end - memory_execute
  jsr $fdf9                     // Filename
  jsr $f34a                     // Open
  sei
  lda #VIC_OUT | DATA_OUT // CLK=0 DATA=1
  sta PORTA_SERIAL              // We're not ready to receive.

// Wait until floppy is active.
wait_fast:
  bit PORTA_SERIAL
  bvs wait_fast                        // Wait for CLK=1 (inverted read!)

  lda #sector_table_end - sector_table // Number of sectors
  sta seccnt
  ldy #0

get_rest_loop:
  bit PORTA_SERIAL
  bvc get_rest_loop             // Wait for CLK=0 (Inverted read!)

// Wait for raster
wait_raster:
  lda CURRENT_RASTER_LINE       // Vertical raster position (bits 0-7)
  cmp #50                       // Between 0-49 or 256-305?
  bcc wait_raster_end           // Yes, so it's safe.
  and #$07                      // Lowest 3 bits
  cmp #$0203                    // Are we in the line before a badline?
  beq wait_raster               // Yes, then wait until we are not.

wait_raster_end:
  lda #VIC_OUT                  // CLK=0 DATA=0
  sta PORTA_SERIAL              // We're ready, start sending!
  pha                           // 3 cycles
  pla                           // 3 cycles
  bit $00                       // 3 cycles
  lda PORTA_SERIAL              // Get 2 bits into bits 6&7
  // Shift and load the other bits into the accumulator.
  .for(var index = 0; index < 3; index++) {
    lsr
    lsr
    eor PORTA_SERIAL
  }

  ldx #VIC_OUT | DATA_OUT       // CLK=0 DATA=1
  stx PORTA_SERIAL              // Not ready any more, don't start sending.

selfmod1:
  sta TARGET,y
  iny
  bne get_rest_loop

  inc selfmod1+2
  dec seccnt
  bne get_rest_loop

infinite_loop:
  jmp infinite_loop

// This is where we overwrite the stack when loading to get our code
// to auto execute. Forces $0203 to be the next instruction.
* = $01ed "Starting Vector"
.fill $11,2

* = $01fe "1541 Command"
memory_execute:
  .text "M-E"
  .word start1541
memory_execute_end:

* = $0203 "Autoexecute"
  jmp main
c64_code_end:

// Must maintain list address to match load area of 1541 buffer.
* = $0206 "1541 Code"
.const sector_index = $05

#import "1541-memory-locations.asm"
// After reading the sector, the contents can be found at $0400 in the buffer.
// This means, the 1541 code can be executed from this buffer.
.pseudopc c64_code_end - main + 4 + c1541.buffer2 {
start1541:
  lda #c1541.CLOCK_OUT
  sta c1541.portB               // Fast code is running!

  lda #0                        // Sector
  sta sector_index
  sta $f9                       // Buffer $0300 for the read.
  lda #TRACK                    // The track we're going to start
                                // loading from.
  sta c1541.buffer1TrackSecHi

read_loop:
  lda sector_index
  lda sector_table,x
  inc sector_index
  bmi end
  sta c1541.buffer1TrackSecLo
  cli
  jsr c1541.readBlock           // Read sector.
  sei

send_loop:
  // We can use $f9 as the byte counter, since we'll return it to 0
  // so it holds the correct buffer number "0" when we read the next
  // sector.
  lda $f9
  lda c1541.buffer1,x

  // First encode
  eor #3                        // Fix up for receiver side (VIC bank!)
  pha                           // Save original
  lsr
  lsr
  lsr
  lsr                           // Get high nybble.
  tax                           // to X
  ldy encode_table,x            // Super-encoded high nybble in Y
  lda #0
  stx c1541.portB                // DATA=0, CLOCK=0 -> we're ready to send!
  pla
  and #$0f                      // Lower nybble
  tax
  lda encode_table,x            // Super-encoded low nybble in A.

wait_for_c64:
  ldx c1541.portB
  bne wait_for_c64              // Needs all 0

  // Then send.
  sta c1541.portB
  asl
  and #$0f
  sta c1541.portB
  tya
  nop
  sta c1541.portB
  asl
  and #$0f
  sta c1541.portB

  jsr c1541.clockOutHi          // Clock=1 10 cycles later.

  inc $f9
  bne send_loop
  beq read_loop

end:
  jmp *

encode_table:
  .byte %1111, %0111, %1101, %0101, %1011, %0011, %1001, %0001
  .byte %1110, %0110, %1100, %0100, %1010, %0010, %1000, %0000

sector_table:
  .byte 0,1,2,3,$ff
sector_table_end:
}
