/*
 * File: fx-title.c
 * Author: dgrubb
 * Date: 23/04/2019
 */

/* Project includes */
#include "fx-credits.h"

extern phrase credits_screen;

void
fx_credits_screen_init()
{
    /* Allocate memory for title background */
    g_credits_background = new_sprite(
            FX_DISPLAY_WIDTH,
            FX_DISPLAY_HEIGHT,
            0, /* X location */
            0, /* Y location */
            DEPTH16, &credits_screen);
}

void
fx_credits_screen_show()
{
    attach_sprite_to_display_at_layer(g_credits_background, g_display, 1);
}

void
fx_credits_screen_hide()
{
    detach_sprite_from_display(g_credits_background);
}

void
fx_credits_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state)
{
    if ((joypad_1_state & (JOYPAD_A | JOYPAD_B | JOYPAD_C)) ||
        (joypad_2_state & (JOYPAD_A | JOYPAD_B | JOYPAD_C))) {
        fx_state_set_screen(StateTitleScreen, 0);
    }
}
