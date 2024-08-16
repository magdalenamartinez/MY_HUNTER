/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/

#include "../include/my_hunter.h"
void change_pantalla(struct spr *sp)
{
    if (sp->ss >= 30 && sp->pantalla == 1) {
        sp->pantalla = 2;
    }
}

void choose_display(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    if (sp->pantalla == 0) {
        sp->disparos = 0;
        pantalla_inicio(window, event, sp);
    }
    if (sp->pantalla == 1) {
        pantalla_juego(window, event, sp);
    }
    if (sp->pantalla == 2) {
        pantalla_fin(window, event, sp);
    }
}

void pantalla_inicio(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    sfVector2f s = {0.4, 0.4}; sfSprite_setScale(sp->boton, s);
    sfVector2f p = {250, 230}; sfSprite_setPosition(sp->boton, p);
    sfVector2f pTitulo = {130, 70};
    sfText_setString(sp->titulo, "My Hunter");
    sfText_setFont(sp->titulo, sp->font);
    sfText_setCharacterSize(sp->titulo, 100);
    sfText_setColor(sp->titulo, sfYellow);
    sfText_setPosition(sp->titulo, pTitulo);
    sfRenderWindow_drawSprite(window, sp->fondo, NULL);
    sfRenderWindow_drawSprite(window, sp->boton, NULL);
    sfRenderWindow_drawText(window, sp->titulo, NULL);
}

void pantalla_juego(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    sfVector2f posObj = {sp->raton.x - 50, sp->raton.y - 40};
    sfVector2f pTitulo = {550, 550}; sfVector2f ppoints = {700, 550};
    sfText_setString(sp->titulo, "Points");
    sfText_setString(sp->points,int_to_str(sp->disparos));
    sfText_setFont(sp->titulo, sp->font);
    sfText_setFont(sp->points, sp->font);
    sfText_setCharacterSize(sp->titulo, 30);
    sfText_setCharacterSize(sp->points, 30);
    sfText_setColor(sp->titulo, sfBlack);
    sfText_setColor(sp->points, sfBlack);
    sfText_setPosition(sp->titulo, pTitulo);
    sfText_setPosition(sp->points, ppoints);
    sfSprite_setPosition(sp->objetivo, posObj);
    sfRenderWindow_drawSprite(window, sp->fondo2, NULL);
    sfRenderWindow_drawSprite(window, sp->bird, NULL);
    sfRenderWindow_drawSprite(window, sp->objetivo, NULL);
    sfRenderWindow_drawText(window, sp->titulo, NULL);
    sfRenderWindow_drawText(window, sp->points, NULL);
}

void pantalla_fin(sfRenderWindow *window, sfEvent event, struct spr *sp)
{
    sfVector2f pTitulo = {250, 300}; sfVector2f ppoints = {500, 300};
    sfVector2f pTitulo2 = {110, 100}; sfText_setString(sp->titulo, "Points");
    sfText_setString(sp->titulo2, "My Hunter");
    sfText_setString(sp->points,int_to_str(sp->disparos));
    sfText_setFont(sp->titulo, sp->font);
    sfText_setFont(sp->titulo2, sp->fuente);
    sfText_setFont(sp->points, sp->font);
    sfText_setCharacterSize(sp->titulo2, 100);
    sfText_setCharacterSize(sp->titulo, 50);
    sfText_setCharacterSize(sp->points, 50);
    sfText_setColor(sp->titulo, sfWhite);
    sfText_setColor(sp->titulo2, sfRed);
    sfText_setColor(sp->points, sfRed);
    sfText_setPosition(sp->titulo2, pTitulo2);
    sfText_setPosition(sp->titulo, pTitulo);
    sfText_setPosition(sp->points, ppoints);
    sfRenderWindow_drawSprite(window, sp->black, NULL);
    sfRenderWindow_drawText(window, sp->titulo2, NULL);
    sfRenderWindow_drawText(window, sp->titulo, NULL);
    sfRenderWindow_drawText(window, sp->points, NULL);
}
