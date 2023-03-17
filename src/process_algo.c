/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** process_algo
*/

#include "bsq.h"

static void check_smallest_nbr(bsq_t bsq, int i, int j)
{
    bsq.top = bsq.tab[i - 1][j];
    bsq.cor = bsq.tab[i - 1][j - 1];
    bsq.lef = bsq.tab[i][j - 1];
    if (bsq.cor < bsq.top && bsq.cor < bsq.lef)
        bsq.tab[i][j] = bsq.cor + 1;
    else if (bsq.top < bsq.lef)
        bsq.tab[i][j] = bsq.top + 1;
    else
        bsq.tab[i][j] = bsq.lef + 1;
}

static bsq_t function_misc(bsq_t bsq, int path, int i, int j)
{
    if (path == 1)
        if (bsq.tab[i][j] != '0')
            check_smallest_nbr(bsq, i, j);
    if (path == 2)
        if (bsq.tab[i][j] > bsq.bgtnbr) {
            bsq.bgtnbr = bsq.tab[i][j];
            bsq.posx = j;
            bsq.posy = i;
        }
    if (path == 3)
        bsq.tab[i][j] = 'x';
    if (path == 4) {
        if (bsq.tab[i][j] != '0' && bsq.tab[i][j] != 'x')
            bsq.tab[i][j] = '.';
        else if (bsq.tab[i][j] != 'x' && bsq.tab[i][j] == '0')
            bsq.tab[i][j] = 'o';
    }
    return bsq;
}

void process_algo(bsq_t bsq)
{
    bsq.bgtnbr = 0;
    for (int i = 1; bsq.tab[i] != NULL; ++i)
        for (int j = 1; bsq.tab[i][j] != '\0'; j++)
            bsq = function_misc(bsq, 1, i, j);
    for (int i = 0; bsq.tab[i] != NULL; i++)
        for (int j = 0; bsq.tab[i][j] != '\0'; j++)
            bsq = function_misc(bsq, 2, i, j);
    for (int i = bsq.posy; i > bsq.posy - (bsq.bgtnbr - 48); i--)
        for (int j = bsq.posx; j > bsq.posx - (bsq.bgtnbr - 48); j--)
            bsq = function_misc(bsq, 3, i, j);
    for (int i = 0; bsq.tab[i] != NULL; i++)
        for (int j = 0; bsq.tab[i][j] != '\0'; j++)
            bsq = function_misc(bsq, 4, i, j);
    for (int i = 0; bsq.tab[i] != NULL; i++)
        my_printf("%s\n", bsq.tab[i]);
    free_tab(bsq);
}
