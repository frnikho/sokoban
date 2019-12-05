/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include "map.h"
#include <ncurses.h>
#include <stdlib.h>

int show_help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n./my_sokoban map\nDESCRIPTION\nmap file");
        my_putstr(" representing the warehouse map, containing ‘#’");
        my_putstr(" for walls,\n‘P’ for the player, ‘X’ for boxes and ");
        my_putstr("‘O’ for storage locations.\n");
        return (1);
    } else {
        return (0);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && show_help(argv))
        return (0);
    char *map_str = read_map(argv[1]);
    if (my_strlen(map_str) <= 1) {
        return (84);
    }
    maps_info_t *info = get_map_info(map_str);
    maps_t *map = convert_map(map_str, info);
    WINDOW *window = initscr();
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        clear();
        display_map(map);
        int current = getch();
        manage_player(map, current);
        refresh();
        if (current == ' ')
            map = convert_map(map_str, info);
        if (check_win(map) || current == 'e')
            break;
    }
    free(map_str);
    destroy_map(map);
    endwin();
    return 0;
}