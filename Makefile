.PHONY: all clean build geniso run test

include make.config

all: geniso

build:
	./scripts/build.sh

geniso: build
	./scripts/iso.sh

clean:
	./scripts/clean.sh

run: geniso
	qemu-system-$(ARCH) -cdrom brandos.iso

test: run clean
