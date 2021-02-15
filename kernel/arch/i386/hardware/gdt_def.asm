 ;
 ; BrandOS
 ; file: gdt.asm  Copyright (C) 2021  Brandon Stevens
 ; 
 ; This program is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ; 
 ; This program is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU General Public License for more details.
 ; 
 ; You should have received a copy of the GNU General Public License
 ; along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ;


; setup segment registers and
; load gdt from gdt pointer with lgdt
global gdt_flush
extern gp
gdt_flush:
    lgdt [gp] ; load gdt
    mov ax, 0x10 ; set ax register to offset of data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2 ; far jump to the offset of code segment
flush2:
    ret ; return to c code
