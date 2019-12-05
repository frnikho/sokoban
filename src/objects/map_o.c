/*
** EPITECH PROJECT, 2019
** map_o.c
** File description:
** map struct function
*/

#include <stdlib.h>
#include "map.h"

maps_t *create_map(maps_info_t *info)
{
    maps_t *map = malloc(sizeof(maps_t));
    map->player = malloc(sizeof(player_t));
    map->walls = malloc(sizeof(wall_t) * info->wall * 2);
    map->boxs = malloc(sizeof(box_t) * info->box * 2);
    map->boxs_location = malloc(sizeof(box_location_t) * info->box_location  * 2);
    return (map);
}

void destroy_map(maps_t *map)
{
    free(map);
}