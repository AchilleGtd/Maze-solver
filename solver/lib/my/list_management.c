/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** list management
*/

#include "../../include/my.h"

path_t *add_path(path_t *path, pos_t position)
{
    path_t *elem = malloc(sizeof(path_t));

    elem->pos.x = position.x;
    elem->pos.y = position.y;
    elem->come_from = path;
    return (elem);
}

path_t *depop(path_t *path, pos_t *pos)
{
    path_t *current = path;

    path = path->come_from;
    if (path) {
        pos->x = path->pos.x;
        pos->y = path->pos.y;
    }
    free(current);
    return (path);
}
