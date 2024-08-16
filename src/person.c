/*
** EPITECH PROJECT, 2022
** bird.c
** File description:
** bird
*/

#include "../include/my_hunter.h"
void reloj_bird(struct spr *sp)
{
    if (sp->ss2 > 0.1) {
        if (sp->rect.left == 220) {
            sp->rect.left = sp->rect.left - 220;
        } else {
            sp->rect.left = sp->rect.left + 110;
        }
    }
    sfSprite_setTextureRect(sp->bird, sp->rect);
    sfSprite_setPosition(sp->bird, sp->birdmov);
    if (sp->ss2 > 0.2) {
        if (sp->birdmov.x < 800) {
            sp->birdmov.x += 1;
        } else {
            sp->birdmov.x = 0;
            sp->birdmov.y = rand() % (500 + 1 - 10) + 10;
        }
        sfClock_restart(sp->relojbird);
    }
}
