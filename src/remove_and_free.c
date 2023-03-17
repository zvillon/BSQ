/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** remove_and_free
*/

#include "bsq.h"

char *remove_first_line(bsq_t bsq)
{
    char *newstr;
    int stock = my_strlen_n(bsq.buf) + 1;

    newstr = malloc(sizeof(char) * ((bsq.st.st_size - stock) + 1));
    newstr[bsq.st.st_size - stock] = '\0';
    bsq.buf[bsq.st.st_size] = '\0';
    for (int i = 0; bsq.buf[i + stock] != '\0'; i++) {
        if (bsq.buf[i + stock] == '\n')
            newstr[i] = '\n';
        else
            newstr[i] = bsq.buf[i + stock];
    }
    free(bsq.buf);
    return newstr;
}

void free_tab(bsq_t bsq)
{
    for (int i = 0; bsq.tab[i] != NULL; i++)
        free(bsq.tab[i]);
    free(bsq.tab);
}