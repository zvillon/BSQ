/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr_unsigned(nb / 10);
        my_put_nbr_unsigned(nb % 10);
    } else
        my_putchar(nb + 48);
    return 0;
}