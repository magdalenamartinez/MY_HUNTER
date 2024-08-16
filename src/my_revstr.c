/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse a string
*/

#include "../include/my_hunter.h"

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    counter--;
    int n = counter / 2;
    while (i <= n) {
        temp = str[i];
        str[i] = str[counter];
        str[counter] = temp;
        i++;
        counter--;
    }
    return (str);
}
