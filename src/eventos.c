/*
** EPITECH PROJECT, 2022
** events.c
** File description:
** events
*/

#include "../include/my_hunter.h"
#include <stdio.h>
void event_click(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    int num = 0; sp->c = 0; int var = 0;
    sp->raton = sfMouse_getPositionRenderWindow(window);
    if (sp->raton.x >= 290 && sp->raton.x <= 540) {
        var = 1;
    }
    if (var == 1 && sp->raton.y >= 260 && sp->raton.y <= 340) {
        if (event.type == sfEvtMouseButtonPressed && sp->pantalla == 0) {
            sp->pantalla = 1; sp->c = 1;
        }
    }
    if (var == 1 && sp->raton.y >= 260 && sp->raton.y <= 340) {
        if (event.type == sfEvtMouseButtonPressed && sp->pantalla == 0) {
            sp->c = 1;
        }
    }
}
