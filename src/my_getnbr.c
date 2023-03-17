/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnbr
*/

#include <stdlib.h>
#include <stdio.h>
#include "../includes/printf.h"

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return 1;
    else if (power == 0 || nb < 0)
        return (0);
    else
        return (nb = nb * my_compute_power_rec(nb, power - 1));
}

int my_numcount(char const *str)
{
    int i = 0;
    int num = 0;

    for (; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; ++i);
    for (; str[i] >= '0' && str[i] <= '9'; ++i)
        ++num;
    return num;
}

int my_subcount(char const *str)
{
    int sub = 0;

    for (int i = 0; str[i] < 48 || str[i] > 57; ++i) {
        if (str[i] == 45)
            ++sub;
    }
    return sub;
}

int my_opecount(char const *str)
{
    int i;
    int ope = 0;

    for (i = 0; str[i] < 48 || str[i] > 57; i++) {
        if (str[i] == '\0') {
            return ope;
        }
        ope++;
    }
    return ope;
}

int my_getnbr(char const *str)
{
    int sub = my_subcount(str);
    int ope = my_opecount(str);
    int num = my_numcount(str) - 1;
    int res = 0;
    int stck = ope;

    for (; str[stck] >= 48 && str[stck] <= 57; ++stck) {
        res = res + (str[stck] - '0') * my_compute_power_rec(10, num);
        num--;
    }
    sub = sub % 2;
    if (sub == 1)
        res = -res;
    return res;
}