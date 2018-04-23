if not exist build mkdir build
java -jar ..\..\Downloads\KickAssembler\KickAss.jar -vicesymbols -odir ..\build -fillbyte 235 src\boot.asm

c1541 -format "test," d64 build\test.d64
c1541 build\test.d64 -write build\boot.prg
