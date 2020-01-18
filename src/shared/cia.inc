#importonce
.filenamespace cia

.const LEFT_SHIFT_ROW = 0
.const LEFT_SHIFT_COLUMNS = 7
.label ALL_COLUMNS = %00000000

.label PIO0 = %00000001
.label PIO1 = %00000010
.label PIO2 = %00000100
.label PIO3 = %00001000
.label PIO4 = %00010000
.label PIO5 = %00100000
.label PIO6 = %01000000
.label PIO7 = %10000000

.namespace cia1 {
.label BASE = $dc00

.label PORTA = BASE + $00 // Port register A

.label KBD_COLUMN0 = PIO0 ^ $ff
.label KBD_COLUMN1 = PIO1 ^ $ff
.label KBD_COLUMN2 = PIO2 ^ $ff
.label KBD_COLUMN3 = PIO3 ^ $ff
.label KBD_COLUMN4 = PIO4 ^ $ff
.label KBD_COLUMN5 = PIO4 ^ $ff
.label KBD_COLUMN6 = PIO5 ^ $ff
.label KBD_COLUMN7 = PIO5 ^ $ff

.label JOY1_UP = PIO0 ^ $ff
.label JOY1_DOWN = PIO1 ^ $ff
.label JOY1_LEFT = PIO2 ^ $ff
.label JOY1_RIGHT = PIO3 ^ $ff
.label JOY1_FIRE = PIO4 ^ $ff

.label PADDLE_ENPORT1 = PIO6
.label PADDLE_ENPORT2 = PIO7
.label PADDLE_EN_MASK = PIO5 | PIO4 | PIO3 | PIO2 | PIO1 | PIO0

.label PORTB = BASE + $01 // Port register B

.label KBD_ROW0 = PIO0 ^ $ff
.label KBD_ROW1 = PIO1 ^ $ff
.label KBD_ROW2 = PIO2 ^ $ff
.label KBD_ROW3 = PIO3 ^ $ff
.label KBD_ROW4 = PIO4 ^ $ff
.label KBD_ROW5 = PIO5 ^ $ff
.label KBD_ROW6 = PIO6 ^ $ff
.label KBD_ROW7 = PIO7 ^ $ff

.label JOY2_UP = PIO0 ^ $ff
.label JOY2_DOWN = PIO1 ^ $ff
.label JOY2_LEFT = PIO2 ^ $ff
.label JOY2_RIGHT = PIO3 ^ $ff
.label JOY2_FIRE = PIO4 ^ $ff

.label DDRA = BASE + $02 // Data direction register A
.label PIO0_OUTPUT = PIO0
.label PIO0_INPUT = %00000000
.label PIO1_OUTPUT = PIO1
.label PIO1_INPUT = %00000000
.label PIO2_OUTPUT = PIO2
.label PIO2_INPUT = %00000000
.label PIO3_OUTPUT = PIO3
.label PIO3_INPUT = %00000000
.label PIO4_OUTPUT = PIO4
.label PIO4_INPUT = %00000000
.label PIO5_OUTPUT = PIO5
.label PIO5_INPUT = %00000000
.label PIO6_OUTPUT = PIO6
.label PIO6_INPUT = %00000000
.label PIO7_OUTPUT = PIO7
.label PIO7_INPUT = %00000000
}

.namespace cia2 {
.label BASE = $dd00

.label PORTA = BASE + $00 // Port register A

.label VIC2_BANK = %00000011
.label VIC2_BANK0 = %00000000
.label VIC2_BANK1 = PIO0
.label VIC2_BANK2 = PIO1
.label VIC2_BANK3 = PIO1 | PIO0
.label VIC2_BANK_SHIFT = 0
.label VIC2_BANK_MASK = VIC2_BANK

.label RS232_TXD = PIO2
.label SERIAL_ATN_OUT = PIO3
.label SERIAL_CLK_OUT = PIO4
.label SERIAL_DATA_OUT = PIO5
.label SERIAL_CLK_IN = PIO6
.label SERIAL_DATA_IN = PIO7
}
