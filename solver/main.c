/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** solve the maze
*/

#include "include/my.h"

int solver(char *filename)
{
    char **maze = get_maze(filename);
    int error;

    if (!maze)
        return (84);
    error = nail_it(maze);
    if (error == 84) {
        write(1, "no solution found\n", 18);
        return (0);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (solver(av[1]));
}
