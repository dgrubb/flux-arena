/*
 * File: fx-display.c
 * Author: dgrubb
 * Date: 17/04/2019
 */

#include "fx-display.h"

display *g_display = 0;

void
fx_display_init()
{
    /* An argument of 0 implies the display will be 
     * capable of handling DISPLAY_DFLT_MAX_SPRITE number 
     * of sprites. Defined as 256.
     */
    g_display = new_display(0);
    g_display->x = FX_DISPLAY_OFFSET;
    show_display(g_display);
}
