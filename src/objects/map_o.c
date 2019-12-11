/*
** EPITECH PROJECT, 2019
** map_o.c
** File description:
** map struct function
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>
#include "map.h"

maps_t *create_map(maps_info_t *info)
{
    maps_t *map = malloc(sizeof(maps_t));
    if (!map)
        return (0);
    map->player = malloc(sizeof(player_t));
    if (!map->player)
        return (0);
    map->walls = malloc(sizeof(wall_t) * info->wall * 5);
    if (!map->walls)
        return (0);
    map->boxs = malloc(sizeof(box_t) * info->box * 5);
    if (!map->boxs)
        return (0);
    map->boxs_loc = malloc(sizeof(box_location_t)*info->box_location*5);
    if (!map->boxs_loc)
        return (0);
    return (map);
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

void destroy_map(maps_t *map)
{
    if (!map)
        return;
    free(map);
}