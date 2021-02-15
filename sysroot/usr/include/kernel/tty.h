/*
 * BrandOS
 * file: tty.h  Copyright (C) 2021  Brandon Stevens
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _BRANDOS_TTY_H
#define _BRANDOS_TTY_H

#include <stddef.h>
#include <stdint.h>

void tty_initialize(void);

void tty_setcolor(uint8_t color);
void tty_putchar(char c);
void tty_write(const char* data, size_t size);
void tty_writestring(const char* data);

void tty_set_cursor(size_t col, size_t row);
void tty_update_cursor();
void tty_newline();
void tty_vga_memcpy(size_t dstrow, size_t srcrow);
void tty_scroll();

void tty_putentryat(unsigned char c, uint8_t color, size_t x, size_t y);

void tty_backspace();

#endif /* _BRANDOS_TTY_H */
