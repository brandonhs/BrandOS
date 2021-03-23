SRC_DIR = src

# system toolchain
TOOLCHAIN = toolchain/elf-i686/bin
PREFIX = $(PWD)/$(TOOLCHAIN)/i686-elf
export CC = $(PREFIX)-gcc
export LD = $(PREFIX)-ld
export AS = $(PREFIX)-as

export SYSROOT = $(PWD)/root/
export INCLUDEDIR = $(SYSROOT)usr/local/include/
export ISO_DIR = $(PWD)/isodir
DESTDIR = $(SYSROOT)

export WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
			-Wwrite-strings \
			-Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
			-Wconversion
export CFLAGS := -g -std=gnu11 -O2 -nostdlib -lgcc $(WARNINGS)

CC += --sysroot=$(SYSROOT) -isystem=$(INCLUDEDIR) -I$(INCLUDEDIR)
CFLAGS += -ffreestanding -Wall -Wextra -Iinclude

.PHONY: all clean image install

all: image

install: install-headers
	$(MAKE) -C src

install-headers:
	mkdir -p $(INCLUDEDIR)
	cp -rp include/* $(INCLUDEDIR)

image: install
	mkdir -p $(ISO_DIR)/boot/grub
	cp -rp grub/grub.cfg $(ISO_DIR)/boot/grub
	grub-mkrescue -o osdev.iso $(ISO_DIR)/

qemu-run: image
	qemu-system-i386 osdev.iso

clean:
	rm -rf $(SYSROOT)*
	rm -rf $(ISO_DIR)
	$(MAKE) -C src clean
