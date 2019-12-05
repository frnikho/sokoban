/*
** EPITECH PROJECT, 2019
** map_player.c
** File description:
** map player function
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

pos_t *find_player(char *map)
{
    int x = 1;
    int y = 1;

    pos_t *position = malloc(sizeof(pos_t));
    for (int i = 0; map[i] != 'P'; i++) {
        if (map[i] == '\n') {
            y++;
        }
        x++;
    }
    position->x = x;
    position->y = y;
    return (position);
}