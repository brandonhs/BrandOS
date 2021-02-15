.PHONY: all clean build geniso run

export PROJECTS=${PWD}/kernel
export ARCH=i386
export TARGET=i686-elf
export CC=${TARGET}-gcc
export AS=nasm
export SYSROOT=${PWD}/sysroot

all: geniso

build:
	./scripts/build.sh

geniso: build
	./scripts/iso.sh

clean:
	./scripts/clean.sh

run:
	qemu-system-$(ARCH) -cdrom brandos.iso
