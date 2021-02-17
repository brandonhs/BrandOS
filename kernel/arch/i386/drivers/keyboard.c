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

#define KBD_US 1
#if KBD_US
#define CTRL_KEY 29
#define LSHIFT_KEY 42
#define RSHIFT_KEY 54
#else
    #error UNKOWN KEYBOARD LAYOUT
#endif

/* keyboard layout */
const unsigned char kbd[128] = {
#if KBD_US
    0,
    '\e', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 
    0, /* ctrl */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, /* shift */
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 
    0, /* caps lock */ 
    '*', 
    0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#endif
};

/* shifted layout */
const unsigned char kbd_sh[128] = {
#if KBD_US
    0,
    '\e', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 
    0, /* ctrl */
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',
    0, /* shift */
    '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 
    0, /* right shift */ 
    '*', 
    0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#endif
};

/* keyboard press buffer */
static unsigned char kbd_buf[KBD_BUF_SIZE];
/* keyboard buffer index */
static int kbd_index=KBD_BUF_SIZE-1;
/* keyboard state object */
static kbd_state_t kbd_state;

/* wrap index */
static int wrap_index(int index) {
    if (index >= KBD_BUF_SIZE) {
        index -= KBD_BUF_SIZE;
    } else if (index < 0) {
        index = KBD_BUF_SIZE-1;
    }
    return index;
}

/* private kbd callback func */
static void _kbd_callback_func(registers_t r) {
    /* retrieve scancode from ps/2 port */
    unsigned char sc = inb(0x60);
    unsigned char c  = kbd[sc];
    if (sc & 0x80) {
        c = 0;
        if (sc-0x80 == LSHIFT_KEY || sc-0x80 == RSHIFT_KEY) {
            kbd_state.shift = STATE_RELEASE;
        }
    }
    else {
        if (sc == LSHIFT_KEY || sc == RSHIFT_KEY) {
            kbd_state.shift = STATE_PRESS;
        } else {
            if (kbd_state.shift == STATE_PRESS) {
                c = kbd_sh[sc];
            }
            kbd_buf[kbd_index] = c;
            if (kbd_index != 0) kbd_index--;
            else kbd_index = KBD_BUF_SIZE-1;
        }
    }
}

void initialize_keyboard() {
    /* register interrupt callback */
    register_interrupt_handler(KBD_IRQ, _kbd_callback_func);

    /* initialize buffer memory and index to zero */
    memset(kbd_buf, 0, KBD_BUF_SIZE);
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
    if (kbd_buf[kbd_index+1] != 0) {
        char a = kbd_buf[++kbd_index];
        if (kbd_index >= KBD_BUF_SIZE) kbd_index=0;
        return a;
    }
    return 0;
}

kbd_state_t get_kbd_state() {
    return kbd_state;
}
