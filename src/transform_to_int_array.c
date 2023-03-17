/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** transform_to_int_array
*/

#include "bsq.h"

int get_nbr_firstline(char const *str)
{
    int nbr;
    char *cnbr;

    cnbr = malloc(sizeof(char) * my_strlen_n(str) + 1);
    cnbr[my_strlen_n(str)] = '\0';
    for (int i = 0; str[i] != '\n'; i++)
        cnbr[i] = str[i];
    nbr = my_getnbr(cnbr);
    free(cnbr);
    return nbr;
}

static void string_to_array(bsq_t bsq, int i, int j, int stk)
{
    if (bsq.buf[stk] == '.')
        bsq.tab[i][j] = '1';
    else if (bsq.buf[stk] == 'o')
        bsq.tab[i][j] = '0';
}

void change_number_array(bsq_t bsq)
{
    int nbr = get_nbr_firstline(bsq.buf);
    int stk = 0;
    int stk2 = my_strlen_n(bsq.buf) + 1;

    bsq.buf = remove_first_line(bsq);
    bsq.buf[bsq.st.st_size - stk2] = '\0';
    bsq.tab = malloc(sizeof(char *) * (nbr + 1));
    bsq.tab[nbr] = NULL;
    for (int i = 0; i < nbr; i++) {
        bsq.tab[i] = malloc(sizeof(char) * (my_strlen_n(bsq.buf) + 1));
        bsq.tab[i][my_strlen_n(bsq.buf)] = '\0';
        for (int j = 0; bsq.buf[stk] != '\n' && bsq.buf[stk] != '\0'; j++) {
            string_to_array(bsq, i, j, stk);
            stk++;
        }
        stk++;
    }
    process_algo(bsq);
    free(bsq.buf);
}