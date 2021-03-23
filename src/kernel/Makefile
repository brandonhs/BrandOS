KERNEL_CSOURCES = $(shell find . -type f -name '*.c')
KERNEL_ASSOURCES = $(shell find . -type f -name '*.S')
KERNEL_OBJS = $(KERNEL_CSOURCES:.c=.o) $(KERNEL_ASSOURCES:.S=.o)

DESTDIR=$(SYSROOT)boot/

.PHONY: all install clean build geniso
.SUFFIXES: .o .c .S

all: install geniso
	echo $(KERNEL_OBJS)

install: build
	mkdir -p $(DESTDIR)
	cp kernel.bin $(DESTDIR)

build: kernel.bin

geniso:
	mkdir -p $(ISO_DIR)/boot
	cp $(shell ls $(DESTDIR)) $(ISO_DIR)/boot/

kernel.bin: $(KERNEL_OBJS)
	$(CC) -T linker.ld -o $@ $(CFLAGS) $(LDFLAGS) $^
	grub-file --is-x86-multiboot $@

clean:
	rm -f $(KERNEL_OBJS) kernel.bin *.d

%.o: %.c
	$(CC) -MD -c $< -o $@ $(CFLAGS)

%.o: %.S
	$(AS) -o $@ $<
