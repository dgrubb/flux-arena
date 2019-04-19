/*
 * File: fx-title.h
 * Author: dgrubb
 * Date: 17/04/2019
 */

#ifndef FX_TITLE_H_
#define FX_TITLE_H_

#include "flux-arena.h"

typedef enum {
    TitleOptionOnePlayer = 0,
    TitleOptionTwoPlayerCoop,
    TitleOptionTwoPlayerBattle,
    TitleOptionOptions,
    TitleOptionCredits,
    TitleOptionCount,
} TitleOption;

sprite *g_title_background;
TitleOption g_current_option;

void fx_title_screen_init();
void fx_title_screen_show();
void fx_title_screen_hide();
void fx_title_update_selection(TitleOption option);
void fx_title_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#endif /* FX_TITLE_H_ */
