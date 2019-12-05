/*
** EPITECH PROJECT, 2019
** map.h
** File description:
** map function
*/

#ifndef MAP_H
#define MAP_H

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct maps_info_s {
    int wall;
    int backline;
    int space;
    int box;
    int box_location;
} maps_info_t;

typedef struct player_s {
    pos_t position;
} player_t;

typedef struct wall_s {
    pos_t position;
} wall_t;

typedef struct box_s {
    pos_t position;
    int is_lock;
} box_t;

typedef struct box_location_s {
    pos_t position;
} box_location_t;

typedef struct maps_s {
    player_t *player;
    wall_t **walls;
    box_t **boxs;
    box_location_t **boxs_location;
    int char_size;
} maps_t;

char *read_map(char *filepath);
pos_t *find_player(char *map);
void move_player(maps_t *map, int current);
maps_t *convert_map(char *map, maps_info_t *info);
maps_info_t *get_map_info(char *map);
void display_info(maps_info_t *info);
maps_t *create_map(maps_info_t *obj_info);
void destroy_map(maps_t *map);
void display_map(maps_t *map);

wall_t *create_wall(int x, int y);
box_t *create_box(int x, int y);
box_location_t *create_box_location(int x, int y);

static char const WALL = '#';
static char const BOX = 'X';
static char const BOXLOCATION = 'O';
static char const PLAYER = 'P';
static char const BACKLINE = '\n';
static char const SPACE = ' ';

#endif
