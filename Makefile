SRC = src
BUILD_DIR = build

TARGET = boot.prg

ASSEMBLER = java -jar ~/Downloads/KickAss/KickAss.jar

build/%.prg : src/%.asm
		$(ASSEMBLER) $< -odir ../build

all: build/$(TARGET)

clean:
		rm -fr build

install: build/$(TARGET)
		c1541 -format "test," d64 test.d64
		c1541 test.d64 -write $<
