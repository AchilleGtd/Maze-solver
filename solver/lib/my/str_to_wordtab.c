/*
** EPITECH PROJECT, 2018
** commande
** File description:
** commande
*/

#include "../../include/my.h"

int how_many(char *string, char delim)
{
    int i = 0;
    int nbr = 0;

    while (string[i]) {
        if (string[i] == delim)
            nbr++;
        i++;
    }
    return (nbr);
}

char *add_line(char *str, int size)
{
    int i = 0;
    char *buf = malloc(sizeof(char) * (size + 1));

    while (i != size) {
        buf[i] = str[i];
        i++;
    }
    buf[size] = '\0';
    return (buf);
}

char **my_str_to_word_tab(char *string, char delim)
{
    int cpt = how_many(string, delim);
    char **tab = malloc(sizeof(char *) * (2 + cpt));
    int i = 0;
    int j = 0;
    int k = 0;
    while (string[i]) {
        if (string[i] == delim) {
            tab[k] = k == 0 ? add_line(&string[j], i - j) :
                add_line(&string[j + 1], i - 1 - j);
            j = i;
            k++;
        }
        i++;
    }
    if (string[i - 1] != delim) {
        tab[k] = add_line(&string[j + 1], i - j - 1);
        k++;
    }
    tab[k] = NULL;
    return (tab);
}
