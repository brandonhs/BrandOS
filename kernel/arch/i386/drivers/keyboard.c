/**
 * BrandOS
 * file: keyboard.c  Copyright (C) 2021  Brandon Stevens
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


#include <kernel/brandos.h>
#include <drivers/keyboard.h>

#include <string.h>
#include <printk.h>
#include <stdint.h>

#include <i386/isr.h>

#define KBD_IRQ IRQ1
#define KBD_BUF_SIZE 512 /* kbd buffer size in bytes */

/* keyboard press buffer */
static unsigned char kbd_buf[KBD_BUF_SIZE];
/* keyboard buffer index */
static int kbd_index;
/* keyboard state object */
static kbd_state_t kbd_state;

/* private kbd callback func */
static void _kbd_callback_func(registers_t r) {
    inb(0x60); /* TODO: keyboard functions */
}

static int wrap_index(int index) {
    if (index >= KBD_BUF_SIZE) {
        index -= KBD_BUF_SIZE;
    } else if (index < 0) {
        index = KBD_BUF_SIZE-1;
    }
    return index;
}

void initialize_keyboard() {
    /* register interrupt callback */
    register_interrupt_handler(KBD_IRQ, _kbd_callback_func);

    /* initialize buffer memory and index to zero */
    memset(kbd_buf, 0, KBD_BUF_SIZE);
    kbd_index = 0;
    /* reset kbd_states */
    kbd_state.caps_lock = STATE_RELEASE;
    kbd_state.shift = STATE_RELEASE;
}

unsigned char read(int index) {
    index = wrap_index(index);
    return kbd_buf[index];
}

unsigned char read_next() {
    /* pop value from buffer */
    unsigned char c = read(kbd_index);
    kbd_buf[kbd_index--] = 0;
    return c;
}

kbd_state_t get_kbd_state() {
    return kbd_state;
}
