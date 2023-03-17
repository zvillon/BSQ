/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "includes/bsq.h"

int manage_error(bsq_t bsq)
{
    if (bsq.buf[0] == '\0') {
        free(bsq.buf);
        return 84;
    }
    bsq.size = my_strlen_n(bsq.buf);
    for (int i = 0; i < bsq.size; i++)
        if (bsq.buf[i] < '0' || bsq.buf[i] > '9') {
            free(bsq.buf);
            return 84;
        }
    return 0;
}

int main(int ac, char **av)
{
    struct bsq bsq;

    if (ac != 2)
        return 84;
    bsq.ret_val = fs_open_file(av[1], bsq);
    if (bsq.ret_val == 84 || bsq.ret_val == -1)
        return 84;
    return 0;
}
