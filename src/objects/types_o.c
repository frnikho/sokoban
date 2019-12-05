/*
** EPITECH PROJECT, 2019
** types_o.c
** File description:
** wall struct function
*/
#include <stdlib.h>
#include "my.h"
#include "map.h"

wall_t *create_wall(int x, int y)
{
    wall_t *p = malloc(sizeof(wall_t));
    p->pos.x = x;
    p->pos.y = y;
    return (p);
}

box_t *create_box(int x, int y)
{
    box_t *p = malloc(sizeof(box_t));
    p->pos.x = x;
    p->pos.y = y;
    p->is_lock = 0;
    return (p);
}

box_location_t *create_box_location(int x, int y)
{
    box_location_t *p = malloc(sizeof(box_location_t));
    p->pos.x = x;
    p->pos.y = y;
    return (p);
}

player_t *create_player(int x, int y)
{
    player_t *p = malloc(sizeof(player_t));
    p->pos.x = x;
    p->pos.y = y;
    return (p);
}