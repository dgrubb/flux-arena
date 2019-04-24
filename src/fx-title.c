/*
 * File: fx-title.c
 * Author: dgrubb
 * Date: 17/04/2019
 */

/* Project includes */
#include "fx-title.h"

extern phrase title_screen;
extern animation_chunk fx_title_credits_foc_anim;

extern phrase fx_title_single_foc;
extern phrase fx_title_single_un;
extern phrase fx_title_two_coop_foc;
extern phrase fx_title_two_coop_un;
extern phrase fx_title_two_bat_foc;
extern phrase fx_title_two_bat_un;
extern phrase fx_title_opt_foc;
extern phrase fx_title_opt_un;
extern phrase fx_title_credits_foc;
extern phrase fx_title_credits_un;

sprite *g_title_background = 0;
sprite *g_option_marker = 0;
int g_current_option = TITLE_OPTION_ONE_PLAYER;
struct TitleOptionElement g_option_table[] = { {0}, {0}, {0}, {0}, {0} };

void
fx_title_screen_init()
{
    /* Allocate memory for title background */
    g_title_background = new_sprite(
            FX_DISPLAY_WIDTH,
            FX_DISPLAY_HEIGHT,
            0, /* X location */
            0, /* Y location */
            DEPTH16, &title_screen);

    /* Create the marker which appears next to the title
     * screen option which the user is currently focused.
     */
    //g_option_marker = new_sprite();

    /* Populate all the user options */
    g_option_table[TITLE_OPTION_ONE_PLAYER].focused_spr = new_sprite(
            TITLE_OPTION_ONE_PLAYER_SIZE_WIDTH_FOCUSED,
            TITLE_OPTION_ONE_PLAYER_SIZE_HEIGHT_FOCUSED,
            TITLE_OPTION_ONE_PLAYER_POS_X_FOCUSED,
            TITLE_OPTION_ONE_PLAYER_POS_Y_FOCUSED,
            DEPTH16, &fx_title_single_foc);
    g_option_table[TITLE_OPTION_ONE_PLAYER].unfocused_spr = new_sprite(
            TITLE_OPTION_ONE_PLAYER_SIZE_WIDTH_UNFOCUSED,
            TITLE_OPTION_ONE_PLAYER_SIZE_HEIGHT_UNFOCUSED,
            TITLE_OPTION_ONE_PLAYER_POS_X_UNFOCUSED,
            TITLE_OPTION_ONE_PLAYER_POS_Y_UNFOCUSED,
            DEPTH16, &fx_title_single_un);
    g_option_table[TITLE_OPTION_ONE_PLAYER].focused = 0;

    g_option_table[TITLE_OPTION_TWO_PLAYER_COOP].focused_spr = new_sprite(
            TITLE_OPTION_TWO_PLAYER_COOP_SIZE_WIDTH_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_SIZE_HEIGHT_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_POS_X_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_POS_Y_FOCUSED,
            DEPTH16, &fx_title_two_coop_foc);
    g_option_table[TITLE_OPTION_TWO_PLAYER_COOP].unfocused_spr = new_sprite(
            TITLE_OPTION_TWO_PLAYER_COOP_SIZE_WIDTH_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_SIZE_HEIGHT_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_POS_X_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_COOP_POS_Y_UNFOCUSED,
            DEPTH16, &fx_title_two_coop_un);
    g_option_table[TITLE_OPTION_TWO_PLAYER_COOP].focused = 0;

    g_option_table[TITLE_OPTION_TWO_PLAYER_BATTLE].focused_spr = new_sprite(
            TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_WIDTH_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_HEIGHT_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_POS_X_FOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_POS_Y_FOCUSED,
            DEPTH16, &fx_title_two_bat_foc);
    g_option_table[TITLE_OPTION_TWO_PLAYER_BATTLE].unfocused_spr = new_sprite(
            TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_WIDTH_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_SIZE_HEIGHT_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_POS_X_UNFOCUSED,
            TITLE_OPTION_TWO_PLAYER_BATTLE_POS_Y_UNFOCUSED,
            DEPTH16, &fx_title_two_bat_un);
    g_option_table[TITLE_OPTION_TWO_PLAYER_BATTLE].focused = 0;

    g_option_table[TITLE_OPTION_OPTIONS].focused_spr = new_sprite(
            TITLE_OPTION_OPTIONS_SIZE_WIDTH_FOCUSED,
            TITLE_OPTION_OPTIONS_SIZE_HEIGHT_FOCUSED,
            TITLE_OPTION_OPTIONS_POS_X_FOCUSED,
            TITLE_OPTION_OPTIONS_POS_Y_FOCUSED,
            DEPTH16, &fx_title_opt_foc);
    g_option_table[TITLE_OPTION_OPTIONS].unfocused_spr = new_sprite(
            TITLE_OPTION_OPTIONS_SIZE_WIDTH_UNFOCUSED,
            TITLE_OPTION_OPTIONS_SIZE_HEIGHT_UNFOCUSED,
            TITLE_OPTION_OPTIONS_POS_X_UNFOCUSED,
            TITLE_OPTION_OPTIONS_POS_Y_UNFOCUSED,
            DEPTH16, &fx_title_opt_un);
    g_option_table[TITLE_OPTION_OPTIONS].focused = 0;

    g_option_table[TITLE_OPTION_CREDITS].focused_spr = new_sprite(
            TITLE_OPTION_CREDITS_SIZE_WIDTH_FOCUSED,
            TITLE_OPTION_CREDITS_SIZE_HEIGHT_FOCUSED,
            TITLE_OPTION_CREDITS_POS_X_FOCUSED,
            TITLE_OPTION_CREDITS_POS_Y_FOCUSED,
            DEPTH16, &fx_title_credits_foc);
    g_option_table[TITLE_OPTION_CREDITS].unfocused_spr = new_sprite(
            TITLE_OPTION_CREDITS_SIZE_WIDTH_UNFOCUSED,
            TITLE_OPTION_CREDITS_SIZE_HEIGHT_UNFOCUSED,
            TITLE_OPTION_CREDITS_POS_X_UNFOCUSED,
            TITLE_OPTION_CREDITS_POS_Y_UNFOCUSED,
            DEPTH16, &fx_title_credits_un);
    g_option_table[TITLE_OPTION_CREDITS].focused = 0;
    g_option_table[TITLE_OPTION_CREDITS].focused_spr->animation = &fx_title_credits_foc_anim;
    g_option_table[TITLE_OPTION_CREDITS].focused_spr->animated = 1;
    g_option_table[TITLE_OPTION_CREDITS].focused_spr->animation_data.counter = 1;
    g_option_table[TITLE_OPTION_CREDITS].focused_spr->animation_data.index = 0;
}

void
fx_title_screen_show()
{
    int i;
    attach_sprite_to_display_at_layer(g_title_background, g_display, 1);
    for (i=0; i<TITLE_OPTION_COUNT; i++) {
        fx_title_focus_element(i, 0);
    }
    g_current_option = TITLE_OPTION_DEFAULT;
    fx_title_focus_element(g_current_option, 1);
}

void
fx_title_focus_element(int option, int set_focus)
{
    if (set_focus) {
        g_option_table[option].focused = 1;
        detach_sprite_from_display(g_option_table[option].unfocused_spr);
        attach_sprite_to_display_at_layer(g_option_table[option].focused_spr, g_display, 1);
    } else {
        g_option_table[option].focused = 0;
        detach_sprite_from_display(g_option_table[option].focused_spr);
        attach_sprite_to_display_at_layer(g_option_table[option].unfocused_spr, g_display, 1);
    }
    /* TODO: update marker */
}

void
fx_title_update_selection(int option)
{
    fx_title_focus_element(g_current_option, 0);
    g_current_option = option;
    fx_title_focus_element(g_current_option, 1);
}

void
fx_title_screen_hide()
{
    /* For perfromance reasons it's better to remove sprites altogether
     * as they will still be processed by the Object Processor, even if
     * off-screen.
     */
    int i;
    detach_sprite_from_display(g_title_background);
    for (i=0; i<TITLE_OPTION_COUNT; i++) {
        detach_sprite_from_display(g_option_table[i].focused_spr);
        detach_sprite_from_display(g_option_table[i].unfocused_spr);
    }
}

void
fx_title_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state)
{
    int new_option;

    if ((joypad_1_state & JOYPAD_A) || (joypad_1_state & JOYPAD_B) || (joypad_1_state & JOYPAD_C)) {
        if (g_current_option == TITLE_OPTION_CREDITS) {
            fx_state_set_screen(StateCreditsScreen, 0);
            return;
        }
    }

    if (joypad_1_state & JOYPAD_UP) {
        if (g_current_option == TITLE_OPTION_ONE_PLAYER) {
            new_option = TITLE_OPTION_COUNT - 1;
        } else {
            new_option = g_current_option - 1;
        }
        fx_title_update_selection(new_option);
    } else if (joypad_1_state & JOYPAD_DOWN) {
        if (g_current_option == (TITLE_OPTION_COUNT - 1)) {
            new_option = TITLE_OPTION_ONE_PLAYER;
        } else {
            new_option = g_current_option + 1;
        }
        fx_title_update_selection(new_option);
    }
}
