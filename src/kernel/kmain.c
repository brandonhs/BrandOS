#include <drivers/vga.h>

int kmain( void ) {
    vga_initialize();

    vga_writestring("Hello, Kernel World!");

    return 0;
}
