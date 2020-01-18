// Zeropage
.label loader_zp_first = $10
.label loadaddrlo = $10
.label loadaddrhi = $11
.label decdestlo = $12
.label decdesthi = $13
.label bytesloadedlo = $14
.label bytesloadedhi = $15
.label loader_zp_last = $1d

// Resident
.label loadraw = $0400
.label loadcompd = $040b
.label blocksize = $05bc
.label loadedtab = $06b4

// Install
.label install = $0e8a
