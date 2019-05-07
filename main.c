/*
** EPITECH PROJECT, 2019
** idk
** File description:
** idk
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *word;
    char *new;
    size_t len;

    if (argc != 2)
        return (84);
    if ((word = get_file(argv[1])) == NULL)
        return (84);
    len = strlen(word);
    if ((new = malloc(sizeof(char) * (len + 1))) == NULL)
        return (84);
    new[len] = '\0';
    for (size_t i = 0; i != len; i++)
        new[i] = '*';
    if (game(word, new) == -1)
        return (84);
    free(word);
    free(new);
    return (0);
}
