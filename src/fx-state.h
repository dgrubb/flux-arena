/*
 * File: fx-state.h
 * Author: dgrubb
 * Date: 17/04/2019
 */

#ifndef FX_STATE_H_
#define FX_STATE_H_

#include "flux-arena.h"

#define FX_STATE_JOYPAD_RESET (JOYPAD_STAR | JOYPAD_SHARP)

typedef enum {
    StateTitleScreen = 0,
    StateMenuScreen,
    StateCreditsScreen
} StateScreen;

StateScreen g_current_screen;

void fx_state_set_screen(StateScreen screen, int force);
void fx_state_show_screen(StateScreen screen);
void fx_state_hide_screen(StateScreen screen);
void fx_state_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#endif /* FX_STATE_H_  */
