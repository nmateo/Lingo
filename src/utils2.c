/*
** EPITECH PROJECT, 2019
** CPE_duostumper_5_2018
** File description:
** utils2.c
*/

#include <stddef.h>

void my_clearstr(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
