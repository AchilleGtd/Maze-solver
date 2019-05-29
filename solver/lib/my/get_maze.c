/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** get the maze
*/

#include "../../include/my.h"

int check_line(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != '\n' && str[i] != 'X' && str[i] != '*')
            return (1);
    return (0);
}

char **check_maze(char **maze)
{
    int length = my_strlen(maze[0]);

    for (int i = 0; maze[i]; i++) {
        if (check_line(maze[i]) != 0)
            return (NULL);
        if (my_strlen(maze[i]) == 0)
            return (NULL);
        else if (my_strlen(maze[i]) != length && maze[i][length] != '\0')
            return (NULL);
    }
    return (maze);
}

char **get_maze(char *filename)
{
    char *content = NULL;
    char **maze;

    content = read_file(filename);
    if (!content || !content[0])
        return (NULL);
    maze = my_str_to_word_tab(content, '\n');
    free(content);
    return (check_maze(maze));
}
