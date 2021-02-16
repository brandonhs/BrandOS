/**
 * BrandOS
 * file: isrs.c  Copyright (C) 2021  Brandon Stevens
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


#include <i386/isrs.h>

unsigned char *exception_messages[] = {
    "Division By Zero", 
    "Debug", 
    "Non Maskable Interrupt", 
    "Breakpoint", 
    "Into Detected Overflow", 
    "Out of Bounds", 
    "Invalid Opcode", 
    "No Coprocessor", 
    "Double Fault", 
    "Coprocessor Segment Overrun", 
    "Bad TSS", 
    "Segment Not Present", 
    "Stack Fault", 
    "General Protection Fault", 
    "Page Fault", 
    "Unkown Interrupt", 
    "Coprocessor Fault", 
    "Alignment Check", 
    "Machine Check", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
    "Reserved", 
};
