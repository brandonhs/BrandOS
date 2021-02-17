/**
 * BrandOS
 * file: keyboard.h  Copyright (C) 2021  Brandon Stevens
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


#ifndef _DRIVERS_KEYBOARD_H
#define _DRIVERS_KEYBOARD_H

#define STATE_PRESS   1 /* key state is pressed */
#define STATE_RELEASE 0 /* key state is released */

#include <stdint.h>

/* current states of 'alternate' keys */
typedef struct {
    uint8_t caps_lock, shift;
} kbd_state_t;

/* initialize the keyboard driver */
void initialize_keyboard();

/* read from keyboard buffer */
unsigned char read(int index);
/* read next character from keyboard buffer */
unsigned char read_next();

/* read current state of keyboard EX. caps lock / shift key */
kbd_state_t get_kbd_state();

#endif /* _DRIVERS_KEYBOARD_H */
