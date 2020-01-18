#importonce
.filenamespace vic_ii

.const CYCLES_PER_LINE_PAL = 63
.label CYCLES_PER_LINE_NTSC = 64

.label DISPLAY_LINES_PAL = 312
.label DISPLAY_LINES_NTSC = 263

.label VSYNC_LINE_PAL = 0
.label VSYNC_LINE_NTSC = 20

.label SCREEN_COLUMNS = 40
.label SCREEN_ROWS = 25
.label SCREEN_SIZE = SCREEN_COLUMNS * SCREEN_ROWS

.label BITMAP_BACKGROUND = 0
.label BITMAP_SIZE = SCREEN_SIZE * 8

.label SPRITE_WIDTH = 24
.label SPRITE_POINTERS = $03f8

.label VIC2_IDLE_PATTERN = $3fff

.label BASE = $d000

.label CHARSET_ADDR_UPPERGRAPHIC = $d000
.label CHARSET_ADDR_UPPERLOWER = $d800

.label ROM_CHARSET_UPGFX = CHARSET_ADDR_UPPERGRAPHIC
.label ROM_CHARSET_UPLOW = CHARSET_ADDR_UPPERLOWER

.label VIC2_COLOURRAM = $d800

.label SPRITE_0 = %00000001
.label SPRITE_1 = %00000010
.label SPRITE_2 = %00000100
.label SPRITE_3 = %00001000
.label SPRITE_4 = %00010000
.label SPRITE_5 = %00100000
.label SPRITE_6 = %01000000
.label SPRITE_7 = %10000000

.label SPRITE0_X = BASE + $00 // Sprite 0, x-coordinate bits 0-7
.label SPRITE0_Y = BASE + $01 // Sprite 0, y-coordinate
.label SPRITE1_X = BASE + $02 // Sprite 1, x-coordinate bits 0-7
.label SPRITE1_Y = BASE + $03 // Sprite 1, y-coordinate
.label SPRITE2_X = BASE + $04 // Sprite 2, x-coordinate bits 0-7
.label SPRITE2_Y = BASE + $05 // Sprite 2, y-coordinate
.label SPRITE3_X = BASE + $06 // Sprite 3, x-coordinate bits 0-7
.label SPRITE3_Y = BASE + $07 // Sprite 3, y-coordinate
.label SPRITE4_X = BASE + $08 // Sprite 4, x-coordinate bits 0-7
.label SPRITE4_Y = BASE + $09 // Sprite 4, y-coordinate
.label SPRITE5_X = BASE + $0a // Sprite 5, x-coordinate bits 0-7
.label SPRITE5_Y = BASE + $0b // Sprite 5, y-coordinate
.label SPRITE6_X = BASE + $0c // Sprite 6, x-coordinate bits 0-7
.label SPRITE6_Y = BASE + $0d // Sprite 6, y-coordinate
.label SPRITE7_X = BASE + $0e // Sprite 7, x-coordinate bits 0-7
.label SPRITE7_Y = BASE + $0f // Sprite 7, y-coordinate

.label SPRITES_X_MSB = BASE + $10 // Sprites 0-7, x-coordinates bit 8

.label CONTROL_REGISTER1 = BASE + $11
.label SCROLLY_0 = %00000000
.label SCROLLY_1 = %00000001
.label SCROLLY_2 = %00000010
.label SCROLLY_3 = %00000011
.label SCROLLY_4 = %00000100
.label SCROLLY_5 = %00000101
.label SCROLLY_6 = %00000110
.label SCROLLY_7 = %00000111
.label SCROLLY_MASK = %00000111
.label LINES_24 = %00000000
.label LINES_25 = %00001000
.label DISPLAY_ENABLE = %00010000
.label DISPLAY_DISABLE = %00000000
.label BITMAP_MODE = %00100000
.label TEXT_MODE = %00000000
.label EBCM_MODE = %01000000
.label RASTERLINE_BIT8 = %10000000
.label RASTERLINE_BIT8_SHIFT = 7
.label RASTERLINE_MSB = %10000000
.label RASTERLINE_MSB_SHIFT = 7

.label RASTERLINE = BASE + $12 // Current raster line, raster IRQ trigger line
.label MAX_RASTERLINE_PAL = $0137
.label MAX_RASTERLINE_NTSC = $0105

.label VIC2_STROBE_X = BASE + $13 // Light pen x-position
.label VIC2_STROBE_Y = BASE + $14 // Light pen y-position

.label VIC2_SPR_ENABLE = BASE + $15 // Enabled sprites

.label CONTROL_REGISTER2 = BASE + $16 // Control register 2
.label SCROLLX_0 = %00000000
.label SCROLLX_1 = %00000001
.label SCROLLX_2 = %00000010
.label SCROLLX_3 = %00000011
.label SCROLLX_4 = %00000100
.label SCROLLX_5 = %00000101
.label SCROLLX_6 = %00000110
.label SCROLLX_7 = %00000111
.label SCROLLX_MASK = %00000111
.label COLUMNS_38 = %00000000
.label COLUMNS_40 = %00001000
.label SINGLECOLOUR_MODE = %00000000
.label MULTICOLOUR_MODE = %00010000

.label SPRITE_EXPANDY = BASE + $17 // y-expanded sprites

.label ADDR = BASE + $18 // Character set and bitmap locations
.label SCREEN_MASK = %11110000
.label CHARSET_UPPERGRAPHIC = %00000100 // $d000
.label CHARSET_UPPERLOWER = %00000110 // $d800
.label CHARSET_MASK = %00001110
.label BITMAP_MASK = %00001000

.label INTERRUPT_REQUEST_REGISTER = BASE + $19 // Interrupt Request Register
.label INTERRUPT_MASK_REGISTER = BASE + $1a // Interrupt Mask Register

.label RASTER_IRQ = %00000001
.label SPR_BGR_COLL_IRQ = %00000010
.label SPR_SPR_COLL_IRQ = %00000100
.label LIGHTPEN_IRQ = %00001000
.label IRQ_FLAG = %10000000

.label BG_PRIORITY = BASE + $1b // Sprite-to-background priority

.label SPR_MCOLOUR = BASE + $1c // Sprites multicolour enabled

.label SPR_EXPANDX = BASE + $1d // Sprites x-expansion

.label SPR_COLL = BASE + $1e // Sprite-to-sprite collision
.label SPR_BG_COLL = BASE + $1f // Sprite-to-background collision

.label BORDERCOLOUR         = BASE + $20 // Overscan colour

.label BGCOLOUR = BASE + $21     // Background colour
.label BGCOLOUR0 = BGCOLOUR      // Background colour 0
.label BGCOLOUR1 = BASE + $22    // Background colour 1
.label MULTICOLOUR0 = BGCOLOUR1  // Multicolour 1
.label BGCOLOUR2 = BASE + $23    // Background colour 2
.label MULTICOLOUR1 = BGCOLOUR2  // Multicolour 2
.label BGCOLOUR3 = BASE + $24    // Background colour 3

.label SPR_MCOLOUR0 = BASE + $25 // Sprite multicolour 0
.label SPR_MCOLOUR1 = BASE + $26 // Sprite multicolour 1

.label SPR0_COLOUR          = BASE + $27 // Sprite colour 0
.label SPR1_COLOUR          = BASE + $28 // Sprite colour 1
.label SPR2_COLOUR          = BASE + $29 // Sprite colour 2
.label SPR3_COLOUR          = BASE + $2a // Sprite colour 3
.label SPR4_COLOUR          = BASE + $2b // Sprite colour 4
.label SPR5_COLOUR          = BASE + $2c // Sprite colour 5
.label SPR6_COLOUR          = BASE + $2d // Sprite colour 6
.label SPR7_COLOUR          = BASE + $2e // Sprite colour 7
