#ifndef _DRIVERS_VGA_H
#define _DRIVERS_VGA_H

#include <stddef.h>
#include <stdint.h>

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

void vga_initialize(void);

void vga_setcolor(uint8_t color);
void vga_putchar(char c);
void vga_write(const char* data, size_t size);
void vga_writestring(const char* data);

void vga_set_cursor(size_t col, size_t row);
void vga_update_cursor();
void vga_newline();
void vga_memcpy(size_t dstrow, size_t srcrow);
void vga_scroll();

void vga_putentryat(unsigned char c, uint8_t color, size_t x, size_t y);

void vga_backspace();

#endif /* _DRIVERS_VGA_H */