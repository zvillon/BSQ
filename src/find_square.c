/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** BSQ step 1
*/

#include "../includes/bsq.h"

size_t get_stat_value(char const *filepath, bsq_t bsq)
{
    if (stat(filepath, &bsq.st) != 0)
        return 0;
    return bsq.st.st_size;
}

int read_and_write_map(char const *filepath, bsq_t bsq)
{
    bsq.st.st_size = get_stat_value(filepath, bsq);
    bsq.buf = malloc(sizeof(char) * (bsq.st.st_size + 1));
    if (read(bsq.fd, bsq.buf, bsq.st.st_size) == -1) {
        free(bsq.buf);
        return 84;
    }
    if (manage_error(bsq) == 84)
        return 84;
    change_number_array(bsq);
    return 0;
}

int fs_open_file(char const *filepath, bsq_t bsq)
{
    bsq.fd = (open(filepath, O_RDONLY));
    if (bsq.fd >= 0) {
        if (read_and_write_map(filepath, bsq) == 84) {
            close(bsq.fd);
            return 84;
        }
        close(bsq.fd);
    }
    return bsq.fd;
}
