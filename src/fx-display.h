/*
 * File: fx-display.h
 * Author: dgrubb
 * Date: 17/04/2019
 */

#ifndef FX_DISPLAY_H_
#define FX_DISPLAY_H_

#include "flux-arena.h"

#define FX_DISPLAY_WIDTH 320
#define FX_DISPLAY_HEIGHT 240
#define FX_DISPLAY_OFFSET 19

extern display *g_display;
void fx_display_init();

#endif /* FX_DISPLAY_H_  */
