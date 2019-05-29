/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** solve the maze
*/

#include "../../include/my.h"

pos_t what_size(char **maze)
{
    int i = 0;
    int j = 0;
    pos_t size;

    while (maze[i])
        i++;
    while (maze[0][j])
        j++;
    size.x = j;
    size.y = i;
    return (size);
}

pos_t find_end(char **maze)
{
    int i = 0;
    int j = 0;
    pos_t end;

    while (maze[i + 1])
        i++;
    while (maze[i][j + 1])
        j++;
    if (maze[i][j] != '*') {
        end.x = -1;
        end.y = 0;
        return (end);
    }
    end.x = j;
    end.y = i;
    return (end);
}

maze_t *heuristic_cost(int line, maze_t *maze, char *real_maze, pos_t end)
{
    int i = 0;
    int new_x = 0;
    int new_y = 0;

    while (real_maze[i]) {
        (maze[i].position).x = i;
        (maze[i].position).y = line;
        new_x = i - end.x;
        new_y = line - end.y;
        maze[i].wall = (real_maze[i] == 'X') ? 1 : 0;
        maze[i].done = 0;
        new_x = (new_x < 0) ? -new_x : new_x;
        new_y = (new_y < 0) ? -new_y : new_y;
        maze[i].distance = new_x + new_y;
        i++;
    }
    return (maze);
}

int nail_it(char **real_maze)
{
    pos_t end = find_end(real_maze);
    pos_t size;
    maze_t **maze;
    int i = 0;

    if (end.x == -1)
        return (84);
    size = what_size(real_maze);
    maze = malloc(sizeof(maze_t *) * (size.y));
    if (!maze)
        return (84);
    for (i = 0; i != size.y; i++)
        maze[i] = malloc(sizeof(maze_t) * (size.x));
    for (i = 0; i != size.y; i++)
        maze[i] = heuristic_cost(i, maze[i], real_maze[i], end);
    return (a_star(real_maze, maze, size, end));
}
