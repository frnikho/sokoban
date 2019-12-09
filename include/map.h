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

typedef struct player_s {
    pos_t pos;
} player_t;

typedef struct wall_s {
    pos_t pos;
} wall_t;

typedef struct box_s {
    pos_t pos;
    int is_lock;
} box_t;

typedef struct box_location_s {
    pos_t pos;
} box_location_t;

typedef struct maps_info_s {
    int wall;
    int backline;
    int space;
    int box;
    int box_location;
} maps_info_t;

typedef struct maps_s {
    player_t *player;
    wall_t **walls;
    box_t **boxs;
    box_location_t **boxs_loc;
    int char_size;
} maps_t;

char *read_map(char *filepath);
pos_t *find_player(char *map);
void manage_player(maps_t *map, int current);
maps_t *convert_map(char *map, maps_info_t *info);
maps_info_t *get_map_info(char *map);
void display_info(maps_info_t *info);
maps_t *create_map(maps_info_t *obj_info);
void destroy_map(maps_t *map);
void display_map(maps_t *map);
int check_win(maps_t *map);
int check_stuck_box(maps_t *map);

wall_t *create_wall(int x, int y);
box_t *create_box(int x, int y);
box_location_t *create_box_location(int x, int y);

int check_collision(int a_x, int a_y, maps_t *map);
int move_box(maps_t *map, pos_t v, int index);
int check_box_collision(maps_t *map, pos_t pos, pos_t v);

void my_puterr(char *msg);

static char const WALL = '#';
static char const BOX = 'X';
static char const BOXLOCATION = 'O';
static char const PLAYER = 'P';
static char const BACKLINE = '\n';
static char const SPACE = ' ';

#endif
