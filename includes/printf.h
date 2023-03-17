/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** bsprintf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
int base_finder(char const *format, int i, va_list lst);
void printf_univ_u10(unsigned int nb, unsigned int base);
int flag_finder(char const *format, int i, va_list lst);
int basic_flags(char const *format, int i, va_list lst);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int basic_flags2(char const *format, int i, va_list lst);

#endif /* !PRINTF_H_ */
