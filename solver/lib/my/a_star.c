/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** tries to find shortest path
*/

#include "../../include/my.h"

pos_t what_dir(pos_t position, int dir)
{
    if (dir == 1)
        position.x = position.x + 1;
    if (dir == 2)
        position.y = position.y + 1;
    if (dir == 3)
        position.x = position.x - 1;
    if (dir == 4)
        position.y = position.y - 1;
    if (dir == -1) {
        position.x = 0;
        position.y = 0;
    }
    return (position);
}

int choose(int right, int up, int down, int left)
{
    int min = INT_MAX;

    if (right < min && right != -1)
        min = right;
    if (up < min && up != -1)
        min = up;
    if (down < min && down != -1)
        min = down;
    if (left < min && left != -1)
        min = left;
    if (min == right)
        return (1);
    if (min == down)
        return (2);
    if (min == left)
        return (3);
    if (min == up)
        return (4);
    if (min == INT_MAX)
        return (-1);
}

pos_t find_closest_one(maze_t **maze, pos_t size, pos_t position)
{
    int left = -1, up = -1, down = -1, right = -1;

    if (position.x < size.x - 1)
        if (maze[position.y][position.x + 1].wall == 0
            && maze[position.y][position.x + 1].done == 0)
            right = maze[position.y][position.x + 1].distance;
    if (position.y < size.y - 1)
        if (maze[position.y + 1][position.x].wall == 0
            && maze[position.y + 1][position.x].done == 0)
            down = maze[position.y + 1][position.x].distance;
    if (position.y > 0)
        if (maze[position.y - 1][position.x].wall == 0
            && maze[position.y - 1][position.x].done == 0)
            up = maze[position.y - 1][position.x].distance;
    if (position.x > 0)
        if (maze[position.y][position.x - 1].wall == 0
            && maze[position.y][position.x - 1].done == 0)
            left = maze[position.y][position.x - 1].distance;
    return (what_dir(position, choose(right, up, down, left)));
}

int draw_path(path_t *path, char **real_maze)
{
    path_t *previous;
    if (!path)
        return (84);
    while (path) {
        previous = path;
        real_maze[path->pos.y][path->pos.x] = 'o';
        path = path->come_from;
        free(previous);
    }
    for (int i = 0; real_maze[i]; i++) {
        write(1, real_maze[i], my_strlen(real_maze[i]));
        write(1, "\n", 1);
        free(real_maze[i]);
    }
    return (0);
}

int a_star(char **real_maze, maze_t **maze, pos_t size, pos_t end)
{
    path_t *current = NULL;
    pos_t next;

    next.x = 0;
    next.y = 0;
    maze[0][0].done = 1;
    current = add_path(current, next);
    while (current != NULL && maze[next.y][next.x].distance != 0) {
        next = find_closest_one(maze, size, next);
        maze[next.y][next.x].done = 1;
        if (current && (next.x == 0 && next.y == 0))
            current = depop(current, &next);
        else
            current = add_path(current, next);
    }
    return (draw_path(current, real_maze));
}
