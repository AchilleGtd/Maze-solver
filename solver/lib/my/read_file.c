/*
** EPITECH PROJECT, 2018
** tail
** File description:
** read files
*/

#include "../../include/my.h"
#include <errno.h>

char *read_fd(int fd, size_t size)
{
    char *tmp;
    char *buffer = malloc(sizeof(char) * (size + 1));
    int read_;

    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

char *read_file(char *filename)
{
    int fd;
    int errno;
    struct stat st;

    if (!filename)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "tail: cannot open '", 19);
        write(2, filename, my_strlen(filename));
        write(2, "' for reading: No such file or directory\n", 41);
        return (NULL);
    }
    stat(filename, &st);
    return (read_fd(fd, st.st_size));
}
