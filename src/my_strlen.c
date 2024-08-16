/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
