/*
** EPITECH PROJECT, 2022
** struct.c
** File description:
** struct
*/

#include "../include/my_hunter.h"
void complete_struct(struct spr *spr)
{
    spr -> fondo = crea(sfTexture_createFromFile("./arc/inicio.jpg", NULL));
    spr->fondo2 = crea(sfTexture_createFromFile("./arc/fondo2.jpg", NULL));
    spr -> bird = crea(sfTexture_createFromFile("./arc/bird.png",NULL));
    spr -> boton = crea(sfTexture_createFromFile("./arc/boton.png", NULL));
    spr -> objetivo = crea(sfTexture_createFromFile("./arc/gun.png",NULL));
    spr -> black = crea(sfTexture_createFromFile("./arc/black.jpeg",NULL));
    spr -> c = 0; spr->scaleobj.x = 0.2; spr->scaleobj.y = 0.2;
    sfSprite_setScale(spr->objetivo, spr->scaleobj);
    spr -> pantalla = 0; spr -> ss = 0; spr->points = sfText_create();
    spr -> ss2 = 0; spr->titulo = sfText_create();
    spr->titulo2 = sfText_create();
    spr->music = sfMusic_createFromFile("./arc/zelda.ogg");
    spr -> font = sfFont_createFromFile("./arc/games.ttf");
    spr -> fuente = sfFont_createFromFile("./arc/fuente.otf");
    spr -> BirdPhoto = 0; spr->raton.x = 0; spr->raton.y = 0;
    spr -> birdmov.x = 0; spr -> birdmov.y = 0; spr->disparos = 0;
    spr -> reloj = sfClock_create(); spr -> relojbird = sfClock_create();
    spr ->rect.height = 110; spr->rect.width = 110; spr->rect.left = 0;
    spr->rect.top = 0;
}

sfSprite* crea(sfTexture *t)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, t, sfTrue);
    return (sprite);
}

void function_spr(sfRenderWindow *window, sfEvent event)
{
    struct spr *sp = malloc(sizeof(struct spr));
    sp->fondo = malloc(sizeof(sfSprite*));
    sp->bird = malloc(sizeof(sfSprite*));
    sp->fondo2 = malloc(sizeof(sfSprite*));
    sp->black = malloc(sizeof(sfSprite*));
    sp->boton = malloc(sizeof(sfSprite*));
    sp->objetivo = malloc(sizeof(sfSprite*));
    sp->reloj = malloc(sizeof(sfClock*));
    sp->relojbird = malloc(sizeof(sfClock*));
    sp->titulo = malloc(sizeof(sfText*));
    sp->titulo2 = malloc(sizeof(sfText*));
    sp->font = malloc(sizeof(sfFont*));
    sp->fuente = malloc(sizeof(sfFont*));
    sp->points = malloc(sizeof(sfText*));
    sp->music = malloc(sizeof(sfMusic*));
    complete_struct(sp); bucle_while(window, event, sp);
}
