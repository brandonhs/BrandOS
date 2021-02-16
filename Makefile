.PHONY: all clean build geniso run test debug

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

debug: geniso
	qemu-system-$(ARCH) -S -cdrom brandos.iso -gdb tcp::9000 & gdb -ex "target remote localhost:9000" -ex "symbol-file kernel/kernel.elf"


test: run clean
