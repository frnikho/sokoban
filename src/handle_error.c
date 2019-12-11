/*
** EPITECH PROJECT, 2019
** handle_error.c
** File description:
** handle error function
*/

#include "map.h"
#include "my.h"

void my_puterr(char *msg);

int check_file_argv(char *map_str)
{
    if (my_strlen(map_str) <= 0) {
        my_puterr("error while opening the current file: ");
        return (1);
    }
    return (0);
}

int handle_error(maps_info_t *info)
{
    if (info->player > 1 || info->player <= 0) {
        my_puterr("bad map format: wrong player context");
        return (1);
    }
    if (info->box_location < 1) {
        my_puterr("bad map format: no box location");
        return (1);
    }
    if (info->box_location > info->box) {
        my_puterr("bad map format: not enough box for box location");
        return (1);
    }
    return (0);
}

int show_help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n./my_sokoban map\nDESCRIPTION\nmap file");
        my_putstr(" representing the warehouse map, containing ‘#’");
        my_putstr(" for walls,\n‘P’ for the player, ‘X’ for boxes and ");
        my_putstr("‘O’ for storage locations.\n");
        my_putstr("INPUT\narrows key (move), space (restart) e (exit)");
        return (1);
    } else {
        return (0);
    }
}