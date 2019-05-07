/*
** EPITECH PROJECT, 2019
** idk
** File description:
** idk
*/

#include <stdlib.h>
#include <stddef.h>

void my_free_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (size_t i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}
