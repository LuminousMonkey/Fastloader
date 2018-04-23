#importonce

.filenamespace vicii

.label CURRENT_RASTER_LINE = $d012

.macro @SetBorderColor(color) {
  lda #color
  sta $d020
}

.macro SetBackgroundColor(color) {
  lda #color
  sta $d021
}

.macro SetMultiColor1(color) {
  lda #color
  sta $d022
}

.macro SetMultiColor2(color) {
  lda #color
  sta $d023
}

.macro SetMultiColorMode() {
  lda $d016
  ora #16
  sta $d016
}

.macro SetScrollMode() {
  lda $D016
  eor #%00001000
  sta $D016
}
