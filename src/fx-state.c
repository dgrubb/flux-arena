/*
 * File: fx-state.c
 * Author: dgrubb
 * Date: 17/04/2019
 */

/* Project includes */
#include "fx-state.h"

StateScreen g_current_screen = StateTitleScreen;

void
fx_state_set_screen(StateScreen screen, int force)
{
    if ((!force) && (screen == g_current_screen)) {
        return;
    }
    fx_state_hide_screen(g_current_screen);
    g_current_screen = screen;
    fx_state_show_screen(g_current_screen);
}

void
fx_state_hide_screen(StateScreen screen)
{
    switch (screen) {
        case StateCreditsScreen:
            fx_credits_screen_hide();
            break;
        case StateTitleScreen:
            fx_title_screen_hide();
            break;
        case StateMenuScreen:
            fx_menu_screen_hide();
            break;
        default:
            break;
    }
}

void
fx_state_show_screen(StateScreen screen)
{
    switch (screen) {
        case StateCreditsScreen:
            fx_credits_screen_show();
            break;
        case StateTitleScreen:
            fx_title_screen_show();
            break;
        case StateMenuScreen:
            fx_menu_screen_show();
            break;
        default:
            break;
    }
}

void
fx_state_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state)
{
    /* If we need to handle system-wide input (e.g.,
     * reset Jaguar via button combination) this is the place
     * to process it. Otherwise, allow the current screen to
     * handle joypad input according to its own unique requirements.
     */
    if (joypad_1_state & FX_STATE_JOYPAD_RESET) {
        fx_settings_init_default();
        fx_state_set_screen(StateTitleScreen, 1);
        return;
    }
    switch (g_current_screen) {
        case StateCreditsScreen:
            fx_credits_screen_joypad_input(joypad_1_state, joypad_2_state);
            break;
        case StateTitleScreen:
            fx_title_screen_joypad_input(joypad_1_state, joypad_2_state);
            break;
        case StateMenuScreen:
            fx_menu_screen_joypad_input(joypad_1_state, joypad_2_state);
            break;
        default:
            break;
    }

}
