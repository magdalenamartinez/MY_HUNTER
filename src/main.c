/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include "../include/my_hunter.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[argc - 1][1] == 'h' && argv[argc - 1][0] == '-' ) {
            my_putstr("This is a game called The Hunter.\n");
            return 0;
        }
    }
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "My Hunter", sfClose, NULL);
    if (!window) {
        return 86;
    }
    sfEvent event;
    function_spr(window, event);
    return 0;
}

void bucle_while(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    sfMusic_play(sp->music);
    srand(time(NULL)); sfTime m; sfTime m2;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            event_closed(window, event);
        }
        m = sfClock_getElapsedTime(sp->reloj);
        m2 = sfClock_getElapsedTime(sp->relojbird);
        sp->ss = m.microseconds / 1000000.0;
        sp->ss2 = m2.microseconds / 100000.0;
        sfRenderWindow_clear(window, sfWhite); change_pantalla(sp);
        event_click(window, event, sp);
        reloj_bird(sp); choose_display(window, event, sp);
        disparado(window, event, sp); sfRenderWindow_display(window);
    }
    sfMusic_stop(sp->music); free(sp->fondo); free(sp->bird); free(sp->fondo2);
    free(sp->boton); free(sp->titulo); free(sp->titulo2); free(sp->points);
    free(sp->objetivo); free(sp->reloj);
    free(sp->relojbird); free(sp);
}

int disparado(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    sfVector2f min; sfVector2f max; sfVector2i pos; int var = 0;
    sp->raton = sfMouse_getPositionRenderWindow(window);
    sfVector2f real = sfSprite_getPosition(sp->bird);
    if (event.type == sfEvtMouseButtonPressed) {
        min.x = sp->birdmov.x - 100;
        min.y = sp->birdmov.y - 100;
        max.x = sp->birdmov.x + 100;
        max.y = sp->birdmov.y + 100;
        if (sp->raton.x <= max.x && sp->raton.x >= min.x) {
            var = 1;
        }
        if ( var == 1 && sp->raton.y <= max.y && sp->raton.y >= min.y) {
            sp->birdmov.x = 0; sp->birdmov.y = rand () % (500 + 1 - 10) + 10;
            sfSprite_setPosition(sp->bird, sp->birdmov); sp->disparos++;
        }
    }
}

void event_closed(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}
