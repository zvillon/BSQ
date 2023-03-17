/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strlen_for_n
*/

int my_strlen_n(char const *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    return i;
}