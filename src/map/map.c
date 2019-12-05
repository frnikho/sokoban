/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map function
*/

#include "my.h"
#include "map.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int check_win(maps_t *map)
{
    for (int i = 0; map->boxs[i] != 0; i++) {
        if (!map->boxs[i]->is_lock)
            return (0);
    }
    return (1);
}

static void draw_character(maps_t *rt, char c, int *index, pos_t *pos)
{
    if (c == WALL)
        rt->walls[index[0]++] = create_wall(pos->x, pos->y);
    if (c == BOX)
        rt->boxs[index[1]++] = create_box(pos->x, pos->y);
    if (c == BOXLOCATION)
        rt->boxs_loc[index[2]++] = create_box_location(pos->x, pos->y);
}

maps_t *convert_map(char *map, maps_info_t *info)
{
    maps_t *rt_map = create_map(info);
    int *index = malloc(sizeof(info));
    pos_t *pos = malloc(sizeof(pos_t));
    pos->x++;
    pos->y++;
    int i = 0;
    for (; map[i] != 0; i++, pos->x++) {
        draw_character(rt_map, map[i], index, pos);
        if (map[i] == PLAYER) {
            player_t *pl = malloc(sizeof(player_t));
            pl->pos.x = pos->x;
            pl->pos.y = pos->y;
            rt_map->player = pl;
        }
        map[i] == BACKLINE ? pos->y++, pos->x=0 : 0;
    }
    rt_map->char_size = i;
    return (rt_map);
}

struct stat get_file_stats(char *filepath)
{
    struct stat stats;
    if (stat(filepath, &stats) == 0) {
        return stats;
    } else {
        my_putstr("error with stats !");
    }
}

char *read_map(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;

    if (fd > 1) {
        int size = get_file_stats(filepath).st_size;
        buffer = malloc(sizeof(char) * size);
        read(fd, buffer, size);
    } else {
        my_putstr("error with read map !");
    }
    return (buffer);
}