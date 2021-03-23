#include <drivers/vga.h>
#include <kernel/string.h>

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t vga_col, vga_row;
static uint8_t vga_color;
static uint16_t* vga_buffer;

/* clear screen */
void vga_initialize(void) {
    vga_row = 0;
    vga_col = 0;
    vga_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    vga_buffer = VGA_MEMORY;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            vga_buffer[index] = vga_entry(' ', vga_color);
        }
    }
}


void vga_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    vga_buffer[index] = vga_entry(c, color);
}


void vga_setcolor(uint8_t color) {
    vga_color = color;
}

void vga_putchar(char c) {
    unsigned char uc = c;
    if (uc == '\n') vga_newline();
    else if (uc == '\b') vga_backspace();
    else {
        vga_putentryat(uc, vga_color, vga_col, vga_row);
        if (++vga_col == VGA_WIDTH) {
            vga_newline();
        }
    }
    if (vga_row == VGA_HEIGHT) {
        --vga_row;
        vga_scroll();
    }
    vga_update_cursor();
}

void vga_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        vga_putchar(data[i]);
}

void vga_writestring(const char* data) {
    vga_write(data, strlen(data));
}


void vga_set_cursor(size_t col, size_t row) {
    uint16_t offset = row * VGA_WIDTH + col;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (offset & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((offset >> 8) & 0xFF));
}

void vga_update_cursor() {
    vga_set_cursor(vga_col, vga_row);
}

void vga_newline() {
    vga_row++;
    vga_col=0;
    vga_update_cursor();
}

void vga_scroll() {
    for (size_t i = 1; i <= VGA_HEIGHT; i++) {
        vga_memcpy(i-1, i);
    }
}

int get_offset(int col, int row) {
    return row * VGA_WIDTH + col;
}

void vga_memcpy(size_t dstrow, size_t srcrow) {
    if (srcrow == dstrow) return; // dont waste time if source == dest
    else if (srcrow > VGA_WIDTH || dstrow > VGA_HEIGHT) return; // we dont want to write to non vga memory

    unsigned short num_bytes = VGA_WIDTH*2;

    uint16_t *source_mem = (uint16_t*)(VGA_MEMORY + get_offset(0, srcrow));
    uint16_t *dest_mem = (uint16_t*)(VGA_MEMORY + get_offset(0, dstrow));

    memcpy(dest_mem, source_mem, num_bytes);
}


void vga_backspace() {
    if (vga_col == 0) {
        vga_col = VGA_WIDTH-1;
        if (vga_row != 0) vga_row--;
    }
    else vga_col--;
    vga_putentryat(' ', vga_color, vga_col, vga_row);
    vga_update_cursor();
}
