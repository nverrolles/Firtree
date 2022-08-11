/*
** EPITECH PROJECT, 2020
** firtree
** File description:
** xmas tree
*/

#include <stdlib.h>
#include "./include/functions.h"

int main (int ac, char **av)
{
    int size = atoi(av[1]);

    tree(size);
    return 0;
}

int tree(int size)
{
    int printed_triangles = 0;
    int last_line_size = calc_last_line(size);
    int center = last_line_size / 2;
    int max_line_star = center + 1;
    int tmp = 1;

    for (int i = 0; i < size; i++) {
        print_triangles(printed_triangles, &center, &max_line_star);
        printed_triangles++;
        if (printed_triangles % 2 == 1)
            tmp++;
        center += tmp;
        max_line_star -= tmp;
    }
    print_trunk(size, (last_line_size / 2));
    return (0);
}

void print_trunk(int size, int center)
{
    int n = 0;
    int pipe_nb = size;

    if (size % 2 == 0)
        pipe_nb++;
    for (int i = 0; i < size; i++) {
        while (n < center - (pipe_nb / 2)) {
            my_putchar(' ');
            n++;
        }
        n = 0;
        while (n < pipe_nb) {
            my_putchar('|');
            n++;
        }
        n = 0;
        my_putchar('\n');
    }
}

void print_triangles(int printed_triangles, int *center, int *max_line_star)
{
    int n = 0;

    for (int i = 0; i < printed_triangles + 4; i++) {
        while (n < *center) {
            my_putchar(' ');
            n++;
        }
        while (n < *max_line_star) {
            my_putchar('*');
            n++;
        }
        n = 0;
        *center -= 1;
        *max_line_star += 1;
        my_putchar('\n');
    }
}

int calc_last_line(int size)
{
    int line = 6;
    int i = 0;
    int last_line_size = 1;

    for (int y = 0; i < size; y++) {
        if (y%2 == 0) {
            line = line + y;
            y = 0;
        }
        last_line_size = last_line_size + line;
        i++;
    }
    return (last_line_size);
}