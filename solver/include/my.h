/*
** EPITECH PROJECT, 2019
** dante's star
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct path_s {
    struct path_s *come_from;
    pos_t pos;
} path_t;

typedef struct maze_s {
    pos_t position;
    int distance;
    char wall;
    char done;
} maze_t;

int my_strlen(char *str);
char **my_str_to_word_tab(char *s, char);
int nail_it(char **);
char **get_maze(char *filename);
char *my_strdup(char *str);
path_t *add_path(path_t *, pos_t);
path_t *depop(path_t *, pos_t *);
char *read_file(char *filename);
int a_star(char **, maze_t **, pos_t, pos_t);
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#endif
