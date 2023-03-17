/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** basic_flag
*/

#include <stdarg.h>
#include <stdio.h>
#include "printf.h"
#include <stdlib.h>

int basic_flags(char const *format, int i, va_list lst)
{
    switch (format[i + 1]) {
    case '%':
        my_putchar(37);
        return (i + 1);
    case 's':
        my_putstr(va_arg(lst, char*));
        return (i + 1);
    case 'c':
        my_putchar(va_arg(lst, int));
        return (i + 1);
    case 'd':
        my_put_nbr(va_arg(lst, int));
        return (i + 1);
    case 'u':
        my_put_nbr_unsigned(va_arg(lst, int));
        return (i + 1);
    }
    return i;
}

int basic_flags2(char const *format, int i, va_list lst)
{
    switch (format[i + 1]) {
    case 'i':
        my_put_nbr(va_arg(lst, int));
        return (i + 1);
    }
    return i;
}