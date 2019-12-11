/*
** EPITECH PROJECT, 2019
** map_win.c
** File description:
** map win window
*/

#include "map.h"
#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

WINDOW *window;
static const char *winmsg = "YOU WIN !!!";

static void init(void)
{
    window = initscr();
    keypad(stdscr, TRUE);
    noecho();
}

void game_win(void)
{
    init();
    int restart = 0;
    while (1) {
        clear();
        mvprintw(LINES/2, (COLS / 2) - 5, "YOU WIN !!!");
        int current = getch();
        refresh();
        if (current == ' ' || current == 'e')
            break;
    }
    endwin();
}