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

int main(int argc, char **argv)
{
    char *map_str = read_map(argv[1]);
    maps_info_t *info = get_map_info(map_str);
    display_info(info);
    maps_t *map = convert_map(map_str, info);
    my_putchar('\n');
    my_putstr(map_str);
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
        if (check_win(map))
            break;
    }
    free(map_str);
    destroy_map(map);
    endwin();
    my_putstr("YOU WIN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    return 0;
}