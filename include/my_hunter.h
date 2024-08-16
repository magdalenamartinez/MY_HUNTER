/*
** EPITECH PROJECT, 2022
** my_hunter.h
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    struct spr {
        sfSprite *fondo; sfSprite *bird; sfSprite *fondo2;
        sfSprite *boton; sfSprite *objetivo; sfSprite *black;
        int c; int pantalla; int ss; float ss2; sfClock *reloj;
        sfVector2i raton; sfClock *relojbird; sfIntRect rect;
        sfVector2f birdmov; int BirdPhoto;
        int disparos; sfVector2f scaleobj;
        sfText *titulo; sfFont *font;
        sfFont *fuente; sfText *points;
        sfText *titulo2; sfMusic *music;
    };
    char* int_to_str(int num);
    int my_putstr(char *str);
    int my_strlen(char const *str);
    void event_closed(sfRenderWindow *window, sfEvent event);
    void bucle_while(sfRenderWindow *window, sfEvent event, struct spr *sp);
    void function_spr(sfRenderWindow *window, sfEvent event);
    void complete_struct(struct spr *spr);
    void choose_display(sfRenderWindow *window, sfEvent event, struct spr *sp);
    void pantalla_inicio(sfRenderWindow *window, sfEvent event, struct spr *sp);
    void pantalla_juego(sfRenderWindow *window, sfEvent event, struct spr *sp);
    sfSprite* crea(sfTexture *t);
    void event_click(sfRenderWindow *window, sfEvent event, struct spr *sp);
    void bird(sfRenderWindow *window, sfEvent event, struct spr *sp);
    void change_pantalla(struct spr *sp);
    void reloj_bird(struct spr *sp);
    void pantalla_fin(sfRenderWindow *window, sfEvent event, struct spr *sp);
    int disparado(sfRenderWindow *window, sfEvent event, struct spr *sp);
    int my_int_length(int n); char *my_revstr(char *str);
#endif /*MY_HUNTER_H_*/
