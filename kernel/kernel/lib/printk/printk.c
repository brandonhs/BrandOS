/**
 * BrandOS
 * file: printk.c  Copyright (C) 2021  Brandon Stevens
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


#include <printk.h>
#include <stddef.h>
#include <string.h>

#include <kernel/brandos.h>

int printk(const char *fmt, ...) {
    va_list args;
    int r;
    // TODO: replace with propper memory allocation
    va_start(args, fmt);
    const size_t n = strlen(fmt);
    for (size_t i=0; i < n; i++) {
        if (fmt[i] == '%') {
            ++i;
            if (fmt[i] == 's') {
                char *a = va_arg(args, char*);
                tty_writestring(a);
            }
        } else {
            tty_putchar(fmt[i]);
        }
    }
}
