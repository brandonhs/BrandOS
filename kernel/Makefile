##
 # BrandOS
 # file: kernel/Makefile  Copyright (C) 2021  Brandon Stevens
 # 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # (at your option) any later version.
 # 
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 # 
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ##


WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion
CFLAGS := -g -std=gnu11 -O2 -nostdlib -lgcc $(WARNINGS)

CC += --sysroot=${DESTDIR} -isystem=$(INCLUDEDIR)
CFLAGS += -ffreestanding -Wall -Wextra -Iinclude

PREFIX?=/usr/
ARCHDIR=arch/$(ARCH)
INCLUDEDIR?=$(PREFIX)include
ARCH_INCLUDEDIR?=$(INCLUDEDIR)/$(ARCH)

include $(ARCHDIR)/make.config
include kernel/make.config

KERNEL_OBJS = \
$(KERNEL_ARCH_OBJS) \
$(KERNEL_DIR_OBJS) \

KERNEL_INCLUDE_DIRS= \
include/. \
$(KERNEL_ARCH_INCLUDE)

.PHONY: all clean install
.SUFFIXES: .o .c .asm

all: install-headers kernel.bin install-kernel kernel.elf

kernel.bin: $(KERNEL_OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LDFLAGS) $(KERNEL_OBJS)
	grub-file --is-x86-multiboot $@

kernel.elf: $(KERNEL_OBJS) $(ARCHDIR)/linker.ld
	$(CC) $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LDFLAGS) $(KERNEL_OBJS)

%.o: %.c
	$(CC) -MD -c $< -o $@ $(CFLAGS)

%.o: %.asm
	$(AS) -f elf32 -o $@ $<

clean:
	rm -f kernel.bin kernel.elf
	rm -f $(KERNEL_OBJS) *.o */*.o */*/*.o
	rm -f $(KERNEL_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-kernel install-headers

install-kernel:
	mkdir -p $(DESTDIR)/boot
	cp kernel.bin $(DESTDIR)/boot

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps $(KERNEL_INCLUDE_DIRS) $(DESTDIR)$(INCLUDEDIR)/
	# make include directory for architecture specific headers
	# mkdir -p $(DESTDIR)$(ARCH_INCLUDEDIR)
	# cp -R --preserve=timestamps $(KERNEL_ARCH_INCLUDE) $(DESTDIR)$(ARCH_INCLUDEDIR)/

-include $(OBJS:.o=.d)
