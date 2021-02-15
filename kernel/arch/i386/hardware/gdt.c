/**
 * BrandOS
 * file: gdt.c  Copyright (C) 2021  Brandon Stevens
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


#include <stdint.h>

#include <i386/gdt.h>

/* Defines a GDT entry */
struct gdt_entry {
    uint16_t limit_low;
    uint8_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

/* Pointer to GDT structure */
struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct gdt_entry gdt[3];
struct gdt_ptr gp;

extern void gdt_flush();

/* setup descriptor in GDT */
void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    struct gdt_entry entry;
    entry.base_high = (base & 0xFFFF);
    entry.base_middle = (base >> 16) & 0xFF;
    entry.base_high = (base >> 24) & 0xFF;

    entry.limit_low = (limit & 0xFFFF);
    entry.granularity = ((limit >> 16) & 0x0F);

    entry.granularity |= (gran & 0xF0);
    entry.access = access;
    gdt[num] = entry;
}

/* install and initialize the GDT. */
void gdt_install() {
    gp.limit = (sizeof(struct gdt_entry)*3)-1;
    gp.base = &gdt;

    gdt_set_gate(0, 0, 0, 0, 0);
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    gdt_flush();
}
