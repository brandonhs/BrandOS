/**
 * BrandOS
 * file: idt.h  Copyright (C) 2021  Brandon Stevens
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


#ifndef _ARCH_I386_IDT_H
#define _ARCH_I386_IDT_H
#include <stdint.h>

void idt_install();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);
#endif
