/*
** EPITECH PROJECT, 2019
** map_info_o.c
** File description:
** map info struct function
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

maps_info_t *get_map_info(char *map)
{
    maps_info_t *info = malloc(sizeof(maps_info_t));
    for (int i = 0; map[i] != 0; i++) {
        map[i] == WALL ? info->wall++ : 0;
        map[i] == BOX ? info->box++ : 0;
        map[i] == BOXLOCATION ? info->box_location++ : 0;
    }
    return (info);
}

void display_info(maps_info_t *info)
{
    my_putstr("Walls: ");
    my_put_nbr(info->wall);
    my_putstr("\nBox: ");
    my_put_nbr(info->box);
    my_putstr("\nBox Location: ");
    my_put_nbr(info->box_location);
    my_putchar('\n');
}