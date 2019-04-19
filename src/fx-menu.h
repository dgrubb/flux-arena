/*
 * File: fx-menu.h
 * Author: dgrubb
 * Date: 18/04/2019
 */

#ifndef FX_MENU_H_
#define FX_MENU_H_

#include "flux-arena.h"

void fx_menu_screen_show();
void fx_menu_screen_hide();
void fx_menu_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#endif /* FX_MENU_H_ */
