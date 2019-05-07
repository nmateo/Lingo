/*
** EPITECH PROJECT, 2019
** idk
** File description:
** idk
*/

#include <string.h>
#include <time.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *get_rand_str_free(char **arr)
{
    size_t i = 0;
    char *str;

    srand(time(NULL));
    for (; arr[i]; i++);
    if ((str = strdup(arr[rand() % (i)])) == NULL) {
        my_free_arr(arr);
        return (NULL);
    } else {
        my_free_arr(arr);
        return (str);
    }
    return (NULL);
}

static void my_clear_str(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            (arr[i][j] == '\n') ?  arr[i][j] = '\0': arr[i][j];
        }
    }
}

static char **my_arr_realloc(char **arr)
{
    char **ret;
    size_t i = 0;
    if (arr == NULL) {
        if ((ret = malloc(sizeof(char *) * 2)) == NULL) {
            my_free_arr(arr);
            return (NULL);
        }
        ret[1] = NULL;
        return (ret);
    }
    for (; arr[i] != NULL; i++);
    if ((ret = malloc(sizeof(char *) * (i + 2))) == NULL)
        return (NULL);
    for (i = 0; arr[i] != NULL; i++)
        if ((ret[i] = strdup(arr[i])) == NULL) {
            my_free_arr(arr);
            return (NULL);
        }
    ret[i + 1] = NULL;
    my_free_arr(arr);
    return (ret);
}

char *get_file(char *path)
{
    FILE *fd = fopen(path, "r");
    size_t i = 0;
    size_t n = 0;
    char **ret = NULL;
    char *line = NULL;

    if (fd == NULL)
        return (NULL);
    for (; getdelim(&line, &n, '\n', fd) != -1; i++) {
        if ((ret = my_arr_realloc(ret)) == NULL) {
            my_free_arr(ret);
            return (NULL);
        } if ((ret[i] = strdup(&line[0])) == NULL) {
            my_free_arr(ret);
            return (NULL);
        }
    }
    my_clear_str(ret);
    free(line);
    fclose(fd);
    return (get_rand_str_free(ret));
}
