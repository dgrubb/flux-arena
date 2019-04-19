/*
 * File: fx-settings.c
 * Author: dgrubb
 * Date: 17/04/2019
 */

/* Project includes */
#include "fx-settings.h"

int g_players = FX_SETTINGS_DEFAULT_PLAYERS;
int g_muted = FX_SETTINGS_DEFAULT_MUTED;
int g_music_volume = FX_SETTINGS_DEFAULT_MUSIC_VOL;
int g_sfx_volume = FX_SETTINGS_DEFAULT_SFX_VOL;

void fx_settings_init_default()
{
    g_players = FX_SETTINGS_DEFAULT_PLAYERS;
    g_muted = FX_SETTINGS_DEFAULT_MUTED;
    g_music_volume = FX_SETTINGS_DEFAULT_MUSIC_VOL;
    g_sfx_volume = FX_SETTINGS_DEFAULT_SFX_VOL;
}
