/*
 * BrandOS
 * file: io.h  Copyright (C) 2021  Brandon Stevens
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


#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

#include <stdint.h>

/* send data byte to specified port */
void outb(uint16_t port, uint8_t data);
/* recieve data byte from specified port */
uint8_t inb(uint16_t port);

/* send data word to specified port */
void outw(uint16_t port, uint16_t data);
/* recieve data word from specified port */
uint16_t inw(uint16_t port);

#endif /* _KERNEL_SYS_H */