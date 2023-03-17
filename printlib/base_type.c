/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** hexa_type
*/

#include <stdarg.h>
#include <stdio.h>
#include "printf.h"
#include <stdlib.h>

void printf_univ_u10(unsigned int nb, unsigned int base)
{
    if (nb >= base)
        printf_univ_u10(nb / base, base);
    my_putchar(nb % base + '0');
}

int base_finder(char const *format, int i, va_list lst)
{
    switch (format[i + 1]) {
    case 'b':
        printf_univ_u10(va_arg(lst, int), 2);
        return (i + 1);
    case 'o':
        printf_univ_u10(va_arg(lst, int), 8);
        return (i + 1);
    }
    return i;
}
