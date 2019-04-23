/*
 * File: fx-credits.h
 * Author: dgrubb
 * Date: 23/04/2019
 */

#ifndef FX_CREDITS_H_
#define FX_CREDITS_H_

#include "flux-arena.h"

sprite *g_credits_background;

void fx_credits_screen_init();
void fx_credits_screen_show();
void fx_credits_screen_hide();
void fx_credits_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#endif /* FX_CREDITS_H_ */
