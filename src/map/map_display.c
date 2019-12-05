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

int check_collision(int a_x, int a_y, maps_t *map)
{
    int x = map->player->position.x + a_x;
    int y = map->player->position.y + a_y;

    for (int i = 0; map->walls[i] != 0; i++) {
        if (map->walls[i]->position.x == x && map->walls[i]->position.y == y)
            return (1);
    }
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (map->boxs[i]->position.x == x && map->boxs[i]->position.y == y)
            return (1);
    }

    return (0);
}

void move_player(maps_t *map, int current)
{
    if (current == KEY_LEFT && !check_collision(-1, 0, map))
        map->player->position.x--;
    if (current == KEY_RIGHT && !check_collision(1, 0, map))
        map->player->position.x++;
    if (current == KEY_UP && !check_collision(0, -1, map))
        map->player->position.y--;
    if (current == KEY_DOWN && !check_collision(0, 1, map))
        map->player->position.y++;
}

void display_map(maps_t *map)
{
    int *index = malloc(sizeof(map));
    pos_t *pos = malloc(sizeof(pos_t));

    for (int i = 0; map->walls[i] != 0; i++)
        mvprintw(map->walls[i]->position.y, map->walls[i]->position.x, "#");
    for (int i = 0; map->boxs[i] != 0; i++)
        mvprintw(map->boxs[i]->position.y, map->boxs[i]->position.x, "X");

    //SEG FAULT HERE
    for (int i = 0; map->boxs_location[i] != 0; i++)
        mvprintw(map->boxs_location[i]->position.y, map->boxs_location[i]->position.x, "O");
    mvprintw(map->player->position.y, map->player->position.x, "P");
    move(map->player->position.y, map->player->position.x);
}