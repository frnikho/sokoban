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

int check_file_argv(char *map_str);
int handle_error(maps_info_t *info);
int show_help(char **argv);

static int win;
maps_t *map;
maps_info_t *info;

static void init(void)
{
    win = 0;
    WINDOW *window = initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);
}

int game_loop(char *map_str)
{
    init();
    while (1) {
        clear();
        display_map(map);
        if (check_win(map)) {
            win = 1;
            break;
        }
        int current = getch();
        manage_player(map, current);
        map = current == ' ' ? convert_map(map_str, info) : map;
        if (current == 'e' || check_stuck_box(map))
            break;
    }
    endwin();
    free(map_str);
    destroy_map(map);
    return (win);
}

int main(int argc, char **argv)
{
    if (argc == 2 && show_help(argv))
        return (0);
    char *map_str = read_map(argv[1]);
    if (check_file_argv(map_str))
        return (84);
    info = get_map_info(map_str);
    map = convert_map(map_str, info);
    if (handle_error(info))
        return (84);
    if (game_loop(map_str))
        return (0);
    return 1;
}