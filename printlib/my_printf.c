/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "printf.h"
#include <stdlib.h>

int flag_finder(char const *f, int i, va_list lst)
{
    if (f[i + 1] == 37 || f[i + 1] == 'd' || f[i + 1] == 's'
    || f[i + 1] == 99 || f[i + 1] == 'u') {
        basic_flags(f, i, lst);
        return (i + 1);
    }
    if (f[i + 1] == 'X' || f[i + 1] == 'x' || f[i + 1] == 98
    || f[i + 1] == 'o') {
        base_finder(f, i, lst);
        return (i + 1);
    }
    if (f[i + 1] == 'i') {
        basic_flags2(f, i, lst);
        return (i + 1);
    }
    my_putchar('%');
    return (i);
}

int my_printf(char const *format, ...)
{
    va_list lst;

    va_start(lst, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = flag_finder(format, i, lst);
        else
            my_putchar(format[i]);
    }
    va_end(lst);
    return 0;
}
