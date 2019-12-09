/*
** EPITECH PROJECT, 2019
** map_display.c
** File description:
** map display function
*/
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "map.h"

int get_walls_near_box(maps_t *map, box_t *box)
{
    int x = box->pos.x;
    int y = box->pos.y;
    int walls = 0;
    for (int i = 0; map->walls[i] != 0; i++) {
        if (x==map->walls[i]->pos.x+1&&y==map->walls[i]->pos.y==y)
            walls++;
        if (x==map->walls[i]->pos.x-1&&y==map->walls[i]->pos.y==y)
            walls++;
        if (x==map->walls[i]->pos.x&&y==map->walls[i]->pos.y+1==y)
            walls++;
        if (x==map->walls[i]->pos.x&&y==map->walls[i]->pos.y-1==y)
            walls++;
    }

    return (walls);
}

int check_stuck_box(maps_t *map)
{
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (get_walls_near_box(map, map->boxs[i]))
            exit(64);
    }
}

static void move_player(maps_t *map, int x, int y)
{
    x == 1 ? map->player->pos.x++ : 0;
    x == -1 ? map->player->pos.x-- : 0;
    y == 1 ? map->player->pos.y++ : 0;
    y == -1 ? map->player->pos.y-- : 0;
}

void manage_player(maps_t *map, int current)
{

    if (current == KEY_LEFT && !check_collision(-1, 0, map))
        move_player(map, -1, 0);
    if (current == KEY_RIGHT && !check_collision(1, 0, map))
        move_player(map, 1, 0);
    if (current == KEY_UP && !check_collision(0, -1, map))
        move_player(map, 0, -1);
    if (current == KEY_DOWN && !check_collision(0, 1, map))
        move_player(map, 0, 1);
}

void display_map(maps_t *map)
{
    int *index = malloc(sizeof(map));
    pos_t *pos = malloc(sizeof(pos_t));

    for (int i = 0; map->walls[i] != 0; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(map->walls[i]->pos.y, map->walls[i]->pos.x, "#");
    }
    for (int i = 0; map->boxs_loc[i] != 0; i++) {
        attron(COLOR_PAIR(2));
        mvprintw(map->boxs_loc[i]->pos.y, map->boxs_loc[i]->pos.x, "O");
    }
    for (int i = 0; map->boxs[i] != 0; i++) {
        attron(COLOR_PAIR(3));
        mvprintw(map->boxs[i]->pos.y, map->boxs[i]->pos.x, "X");
    }
    attron(COLOR_PAIR(4));
    mvprintw(map->player->pos.y, map->player->pos.x, "P");
    move(map->player->pos.y, map->player->pos.x);
}