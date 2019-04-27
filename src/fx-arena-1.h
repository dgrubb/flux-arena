/*
 * File: fx-arena-1.h
 * Author: dgrubb
 * Date: 27/04/2019
 */

#ifndef FX_ARENA_1_H_
#define FX_ARENA_1_H_

#include "flux-arena.h"

sprite *g_arena_1_background;

void fx_arena_1_screen_init();
void fx_arena_1_screen_show();
void fx_arena_1_screen_hide();
void fx_arena_1_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#endif /* FX_ARENA_1_H_ */
