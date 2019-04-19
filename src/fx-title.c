/*
 * File: fx-title.c
 * Author: dgrubb
 * Date: 17/04/2019
 */

/* Project includes */
#include "fx-title.h"

extern phrase title_screen;

sprite *g_title_background = 0;
TitleOption g_current_option = TitleOptionOnePlayer;

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
}

void
fx_title_screen_show()
{
    attach_sprite_to_display_at_layer(g_title_background, g_display, 1);
}

void
fx_title_update_selection(TitleOption option)
{
    g_current_option = option;
    /* TODO: redraw/animate menu sprites here
     */
}

void
fx_title_screen_hide()
{
    /* For perfromance reasons it's better to remove sprites altogether
     * as they will still be processed by the Object Processor, even if
     * off-screen.
     */
    detach_sprite_from_display(g_title_background);
}

void
fx_title_screen_joypad_input(unsigned long joypad_1_state, unsigned long joypad_2_state)
{
    TitleOption new_option;
    if (joypad_1_state & JOYPAD_DOWN) {
        if (g_current_option == TitleOptionOnePlayer) {
            new_option = TitleOptionCount - 1;
        } else {
            new_option = g_current_option - 1;
        }
        fx_title_update_selection(new_option);
        return;
    } else if (joypad_1_state & JOYPAD_UP) {
        new_option = g_current_option + 1;
        if (g_current_option == TitleOptionCount) {
            new_option = TitleOptionOnePlayer;
        }
        fx_title_update_selection(new_option);
        return;
    }
    /* Allow the second player to navigate too, but their input
     * is subservient to the first player's.
     */
    if (joypad_2_state & JOYPAD_DOWN) {
        if (g_current_option == TitleOptionOnePlayer) {
            new_option = TitleOptionCount - 1;
        } else {
            new_option = g_current_option - 1;
        }
        fx_title_update_selection(new_option);
    } else if (joypad_2_state & JOYPAD_UP) {
        new_option = g_current_option + 1;
        if (g_current_option == TitleOptionCount) {
            new_option = TitleOptionOnePlayer;
        }
        fx_title_update_selection(new_option);
    }
}
