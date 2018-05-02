// This contains the full and proper Fastloader that will stay in
// memory.

* = $0400 "Loader Resident"
.import c64 "../resources/loader-c64.prg"

* = $0865 "Loader Install"
.import c64 "../resources/install-c64.prg"

* = $1200 "Main"
main:
  lda variable
  sta $d019
  sta $d020
  inc variable
  jmp main

variable:
  .byte 00
