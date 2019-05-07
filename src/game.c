/*
** EPITECH PROJECT, 2019
** CPE_duostumper_5_2018
** File description:
** game.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *ask_attack(char *word)
{
    char *guess = NULL;
    size_t n = 0;

    printf(">");
    getline(&guess, &n, stdin);
    my_clearstr(guess);
    if (strlen(guess) < strlen(word)) {
        printf("Word too short. Retry.\n");
        free(guess);
        return (NULL);
    } else if (strlen(guess) > strlen(word)) {
        printf("Word too long. Rety.\n");
        free(guess);
        return (NULL);
    } else
        return (guess);
}

static int is_char_instr(char *word, char c, char *new)
{
    int tmp = 0;

    for (size_t i = 0; new[i] != '\0'; i++) {
        if (word[i] == c && new[i] != c)
            tmp++;
    }
    for (size_t i = 0; word[i] != '\0'; i++) {
        if (word[i] == c && tmp != 0)
            return (1);
    }
    return (0);
}

static char *str_check(char *guess, char *word, char *new)
{
    for (size_t i = 0; guess[i] != '\0'; i++) {
        if (guess[i] == word[i]) {
            new[i] = guess[i];
        } else if (is_char_instr(word, guess[i], new) == 1)
            new[i] = '?';
        else
            new[i] = '*';
    }
    printf("%s\n\n", new);
    return (new);
}

static int lingo(char *word, char *new)
{
    char *guess = NULL;

    while ((guess = ask_attack(word)) == NULL);
    new = str_check(guess, word, new);
    if (strcmp(new, word) == 0) {
        free(guess);
        free(new);
        return 1;
    }
    free(guess);
    free(new);
    return (0);
}

int game(char *word, char *new)
{
    char *dup;
    printf("*: invalid letter\n");
    printf("?: incorrectly placed letter\n");
    printf("Will you find the secret word?\n");
    for (size_t i = 0; i < strlen(word); i++) {
        (i == 0) ? printf("%c", word[i]) : printf("*");
    }
    printf("\n\n");
    for (size_t round = 1; round <= strlen(word); round++) {
        if ((dup = strdup(new)) == NULL)
            return (-1);
        printf("Round %d\n", (int)round);
        if (lingo(word, dup) == 1) {
            printf("You won!\n");
            return 0;
        }
    }
    printf("You lost!\n");
    return (0);
}
