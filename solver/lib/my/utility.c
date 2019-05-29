/*
** EPITECH PROJECT, 2019
** dantes
** File description:
** utiity
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char *my_strdup(char *str)
{
    int i = 0;
    int length = my_strlen(str);
    char *buf;

    buf = malloc(sizeof(char) * (1 + length));
    while (str[i]) {
        buf[i] = str[i];
        i++;
    }
    buf[i] = '\0';
    return (buf);
}

