.PHONY: all clean build geniso run

include make.config

all: geniso

build:
	./scripts/build.sh

geniso: build
	./scripts/iso.sh

clean:
	./scripts/clean.sh

run:
	qemu-system-$(ARCH) -cdrom brandos.iso
