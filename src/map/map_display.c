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

int get_count_walls(maps_t *map, box_t *box, int x, int y)
{
    int walls = 0;
    int wall_x = box->pos.x+x;
    int wall_y = box->pos.y+y;
    for (int i = 0; map->walls[i] != 0; i++) {
        int w_x = map->walls[i]->pos.x;
        int w_y = map->walls[i]->pos.y;
        w_x == wall_x && w_y == wall_y ? walls++ : 0;
    }
    return (walls);
}

int get_walls_near_box(maps_t *map, box_t *box)
{
    int walls = 0;
    walls += get_count_walls(map, box, 1, 0);
    walls += get_count_walls(map, box, 0, 1);
    walls += get_count_walls(map, box, -1, 0);
    walls += get_count_walls(map, box, 0, -1);
    return (walls);
}

int check_stuck_box(maps_t *map)
{
    for (int i = 0; map->boxs[i] != 0; i++) {
        int walls = get_walls_near_box(map, map->boxs[i]);
        if (walls >= 2)
            continue;
        else
            return (0);
    }
    return (1);
}

void move_player(maps_t *map, int x, int y)
{
    x == 1 ? map->player->pos.x++ : 0;
    x == -1 ? map->player->pos.x-- : 0;
    y == 1 ? map->player->pos.y++ : 0;
    y == -1 ? map->player->pos.y-- : 0;
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