/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include "printf.h"
    #include <stdlib.h>

typedef struct bsq {
    struct stat st;
    int fd;
    char *buf;
    char **tab;
    long size;
    int top;
    int cor;
    int lef;
    int bgtnbr;
    int posx;
    int posy;
    int ret_val;
} bsq_t;

int fs_open_file(char const *filepath, bsq_t bsq);
int my_strlen_n(char const *str);
int my_getnbr(char const *str);
void change_number_array(bsq_t bsq);
char *remove_first_line(bsq_t bsq);
void process_algo(bsq_t bsq);
void free_tab(bsq_t bsq);
int manage_error(bsq_t bsq);
int get_nbr_firstline(char const *str);

#endif /* !BSQ_H_ */
