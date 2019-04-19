/*
 * File: fx-settings.h
 * Author: dgrubb
 * Date: 17/04/2019
 */

#ifndef FX_SETTINGS_H_
#define FX_SETTINGS_H_

#include "flux-arena.h"

#define FX_SETTINGS_DEFAULT_PLAYERS 1
#define FX_SETTINGS_DEFAULT_MUTED 0
#define FX_SETTINGS_DEFAULT_MUSIC_VOL 50
#define FX_SETTINGS_DEFAULT_SFX_VOL 64

extern int g_players;
extern int g_muted;
extern int g_music_volume;
extern int g_sfx_volume;

void fx_settings_init_default();

#endif /* FX_SETTINGS_H_  */
