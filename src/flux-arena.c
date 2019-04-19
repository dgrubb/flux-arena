/* Project includes */
#include "flux-arena.h"

int
main(int argc, char *argv[])
{
    TOMREGS->vmode = RGB16|CSYNC|BGEN|PWIDTH4|VIDEN;

    /* Removers' library initialisation */
    init_interrupts();
    init_display_driver();

    /* Setup interfaces and initial state */
    fx_display_init();
    fx_title_screen_init();
    fx_state_set_screen(StateTitleScreen, 1);
    joypad_state *j = malloc(sizeof(joypad_state));

    /* Main game loop */
    for (;;) {
        vsync();

        /* Check controller input and direct to the correct screen. The
         * Jaguar can support up to 8 controllers, but this game only 
         * supports up to two players, aka j1 and j2.
         */
        read_joypad_state(j);
        fx_state_joypad_input(j->j1, j->j2);
    }
    return 0;
}
