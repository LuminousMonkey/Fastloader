// Helpful KickAssembler bits.
#importonce

//---------------------------------
// repetition commands
//---------------------------------
.macro ensureImmediateArgument(arg) {
  .if (arg.getType()!=AT_IMMEDIATE) .error "The argument must be immediate!"
}
.pseudocommand asl x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) asl
}
.pseudocommand lsr x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) lsr
}
.pseudocommand rol x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) rol
}
.pseudocommand ror x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) ror
}

.pseudocommand pla x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) pla
}

.pseudocommand nop x {
  :ensureImmediateArgument(x)
  .for (var i=0; i<x.getValue(); i++) nop
}

.pseudocommand pause cycles {
  :ensureImmediateArgument(cycles)
  .var x = floor(cycles.getValue())
  .if (x<2) .error "Cant make a pause on " + x + " cycles"

  // Take care of odd cyclecount
  .if ([x&1]==1) {
    bit $00
    .eval x=x-3
  }

  // Take care of the rest
  .if (x>0)
    :nop #x/2
}
