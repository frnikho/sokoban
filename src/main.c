/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include "map.h"
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

void my_puterr(char *msg)
{
    int length = my_strlen(msg);
    write(2, msg, length);
}

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

int check_file_argv(char *map_str)
{
    if (my_strlen(map_str) <= 0) {
        my_puterr("error while opening the current file: ");
        return (1);
    }
    return (0);
}

static void init()
{
    WINDOW *window = initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);
}

int main(int argc, char **argv)
{
    if (argc == 2 && show_help(argv))
        return (0);
    char *map_str = read_map(argv[1]);
    if (check_file_argv(map_str))
        return (84);
    maps_info_t *info = get_map_info(map_str);
    maps_t *map = convert_map(map_str, info);
    init();
    while (1) {
        clear();
        display_map(map);
        int current = getch();
        manage_player(map, current);
        refresh();
        map = current == ' ' ? convert_map(map_str, info) : map;
        if (check_win(map) || current == 'e')
            break;
    }
    free(map_str);
    destroy_map(map);
    endwin();
    return 0;
}