/*
** EPITECH PROJECT, 2019
** map_collision.c
** File description:
** map collision function
*/

#include "map.h"
#include "my.h"
#include <unistd.h>

void my_puterr(char *msg)
{
    int length = my_strlen(msg);
    write(2, msg, length);
}

int move_box(maps_t *map, pos_t v, int index)
{
    int x = map->boxs[index]->pos.x + v.x;
    int y = map->boxs[index]->pos.y + v.y;
    map->boxs[index]->is_lock = 0;
    for (int i = 0; map->walls[i] != 0; i++) {
        if (map->walls[i]->pos.x == x && map->walls[i]->pos.y == y)
            return (1);
    }
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (map->boxs[i]->pos.x == x && map->boxs[i]->pos.y == y) {
            return (1);
        }
    }
    for (int i = 0; map->boxs_loc[i] != 0; i++) {
        if (map->boxs_loc[i]->pos.x == x && map->boxs_loc[i]->pos.y == y)
            map->boxs[index]->is_lock = 1;
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