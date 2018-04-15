#importonce

// Constants
.const FLOPPY_DATA_OUT = $02
.const FLOPPY_CLOCK_OUT = $08

// Memory Locations
.const C1541_BUFFER0_CMD_CODE = $00

.const C1541_BUFFER1_TRACK_SEC_HI = $06
.const C1541_BUFFER1_TRACK_SEC_LO = $07

.const C1541_BUFFER1 = $0300
.const C1541_BUFFER2 = $0400
.const C1541_BUFFER3 = $0500
.const C1541_BUFFER4 = $0700

.const C1541_PORTB = $1800

// Function calls
.const C1541_READ_BLOCK = $d586
.const C1541_CLOCK_OUT_HI = $e9ae
