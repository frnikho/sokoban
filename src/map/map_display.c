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

static void move_player(maps_t *map, int x, int y)
{
    x == 1 ? map->player->pos.x++ : 0;
    x == -1 ? map->player->pos.x-- : 0;
    y == 1 ? map->player->pos.y++ : 0;
    y == -1 ? map->player->pos.y-- : 0;
}

static int move_box(maps_t *map, pos_t v, int index)
{
    int x = map->boxs[index]->pos.x + v.x;
    int y = map->boxs[index]->pos.y + v.y;

    for (int i = 0; map->walls[i] != 0; i++) {
        if (map->walls[i]->pos.x == x && map->walls[i]->pos.y == y)
            return (1);
    }
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (map->boxs[i]->pos.x == x && map->boxs[i]->pos.y == y)
            return (1);
    }
    for (int i = 0; map->boxs_loc[i] != 0; i++) {
        if (map->boxs_loc[i]->pos.x == x && map->boxs_loc[i]->pos.y == y) {

        }
    }

    map->boxs[index]->pos.x = x;
    map->boxs[index]->pos.y = y;


    return (0);
}

int check_box_collision(maps_t *map, pos_t pos, pos_t v)
{
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (pos.x == map->boxs[i]->pos.x && pos.y == map->boxs[i]->pos.y) {
            return move_box(map, v, i);
        }
    }
    return (1);
}

int check_collision(int a_x, int a_y, maps_t *map)
{
    int x = map->player->pos.x + a_x;
    int y = map->player->pos.y + a_y;

    for (int i = 0; map->walls[i] != 0; i++) {
        if (map->walls[i]->pos.x == x && map->walls[i]->pos.y == y)
            return (1);
    }
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (map->boxs[i]->pos.x == x && map->boxs[i]->pos.y == y) {
            pos_t box_pos = {x, y};
            pos_t v = {a_x, a_y};
            return check_box_collision(map, box_pos, v);
        }
    }

    return (0);
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

    for (int i = 0; map->walls[i] != 0; i++)
        mvprintw(map->walls[i]->pos.y, map->walls[i]->pos.x, "#");
    for (int i = 0; map->boxs_loc[i] != 0; i++)
        mvprintw(map->boxs_loc[i]->pos.y, map->boxs_loc[i]->pos.x, "O");
    for (int i = 0; map->boxs[i] != 0; i++)
        mvprintw(map->boxs[i]->pos.y, map->boxs[i]->pos.x, "X");
    mvprintw(map->player->pos.y, map->player->pos.x, "P");
    move(map->player->pos.y, map->player->pos.x);
}