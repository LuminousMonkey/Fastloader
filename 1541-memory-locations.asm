#importonce
.filenamespace c1541

// Constants
.label DATA_OUT = $02
.label CLOCK_OUT = $08

// Memory Locations
.label buffer0CmdCode = $00

.label buffer1TrackSecHi = $06
.label buffer1TrackSecLo = $07

.label buffer1 = $0300
.label buffer2 = $0400
.label buffer3 = $0500
.label buffer4 = $0700

.label portB = $1800

// Function calls
.label readBlock = $d586
.label clockOutHi = $e9ae
