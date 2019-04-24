/*
 * File: fx-title.h
 * Author: dgrubb
 * Date: 17/04/2019
 */

#ifndef FX_TITLE_H_
#define FX_TITLE_H_

#include "flux-arena.h"

#define TITLE_OPTION_ONE_PLAYER        0
#define TITLE_OPTION_TWO_PLAYER_COOP   1
#define TITLE_OPTION_TWO_PLAYER_BATTLE 2
#define TITLE_OPTION_OPTIONS           3
#define TITLE_OPTION_CREDITS           4
#define TITLE_OPTION_COUNT             5

#define TITLE_OPTION_DEFAULT TITLE_OPTION_ONE_PLAYER

struct TitleOptionElement {
    sprite *focused_spr;
    sprite *unfocused_spr;
    int focused;
};

sprite *g_title_background;
int g_current_option;
struct TitleOptionElement g_option_table[TITLE_OPTION_COUNT];
sprite *g_option_marker;

void fx_title_screen_init();
void fx_title_screen_show();
void fx_title_screen_hide();
void fx_title_focus_element(int option, int set_focus);
void fx_title_update_selection(int option);
void fx_title_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state);

#define TITLE_OPTION_ONE_PLAYER_SIZE_WIDTH_UNFOCUSED         92
#define TITLE_OPTION_ONE_PLAYER_SIZE_HEIGHT_UNFOCUSED        16
#define TITLE_OPTION_ONE_PLAYER_SIZE_WIDTH_FOCUSED           92
#define TITLE_OPTION_ONE_PLAYER_SIZE_HEIGHT_FOCUSED          20
#define TITLE_OPTION_ONE_PLAYER_POS_X_UNFOCUSED              115
#define TITLE_OPTION_ONE_PLAYER_POS_Y_UNFOCUSED              63
#define TITLE_OPTION_ONE_PLAYER_POS_X_FOCUSED                115
#define TITLE_OPTION_ONE_PLAYER_POS_Y_FOCUSED                60

#define TITLE_OPTION_TWO_PLAYER_COOP_SIZE_WIDTH_UNFOCUSED    116
#define TITLE_OPTION_TWO_PLAYER_COOP_SIZE_HEIGHT_UNFOCUSED   16
#define TITLE_OPTION_TWO_PLAYER_COOP_SIZE_WIDTH_FOCUSED      120
#define TITLE_OPTION_TWO_PLAYER_COOP_SIZE_HEIGHT_FOCUSED     18
#define TITLE_OPTION_TWO_PLAYER_COOP_POS_X_UNFOCUSED         103
#define TITLE_OPTION_TWO_PLAYER_COOP_POS_Y_UNFOCUSED         91
#define TITLE_OPTION_TWO_PLAYER_COOP_POS_X_FOCUSED           102
#define TITLE_OPTION_TWO_PLAYER_COOP_POS_Y_FOCUSED           90

#define TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_WIDTH_UNFOCUSED  120
#define TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_HEIGHT_UNFOCUSED 16
#define TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_WIDTH_FOCUSED    124
#define TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_HEIGHT_FOCUSED   18
#define TITLE_OPTION_TWO_PLAYER_BATTLE_POS_X_UNFOCUSED       102
#define TITLE_OPTION_TWO_PLAYER_BATTLE_POS_Y_UNFOCUSED       121
#define TITLE_OPTION_TWO_PLAYER_BATTLE_POS_X_FOCUSED         101
#define TITLE_OPTION_TWO_PLAYER_BATTLE_POS_Y_FOCUSED         120

#define TITLE_OPTION_OPTIONS_SIZE_WIDTH_UNFOCUSED            56
#define TITLE_OPTION_OPTIONS_SIZE_HEIGHT_UNFOCUSED           16
#define TITLE_OPTION_OPTIONS_SIZE_WIDTH_FOCUSED              56
#define TITLE_OPTION_OPTIONS_SIZE_HEIGHT_FOCUSED             18
#define TITLE_OPTION_OPTIONS_POS_X_UNFOCUSED                 134
#define TITLE_OPTION_OPTIONS_POS_Y_UNFOCUSED                 151
#define TITLE_OPTION_OPTIONS_POS_X_FOCUSED                   134
#define TITLE_OPTION_OPTIONS_POS_Y_FOCUSED                   150

#define TITLE_OPTION_CREDITS_SIZE_WIDTH_UNFOCUSED            52
#define TITLE_OPTION_CREDITS_SIZE_HEIGHT_UNFOCUSED           12
#define TITLE_OPTION_CREDITS_SIZE_WIDTH_FOCUSED              52
#define TITLE_OPTION_CREDITS_SIZE_HEIGHT_FOCUSED             14
#define TITLE_OPTION_CREDITS_POS_X_UNFOCUSED                 137
#define TITLE_OPTION_CREDITS_POS_Y_UNFOCUSED                 181
#define TITLE_OPTION_CREDITS_POS_X_FOCUSED                   137
#define TITLE_OPTION_CREDITS_POS_Y_FOCUSED                   180

#endif /* FX_TITLE_H_ */
