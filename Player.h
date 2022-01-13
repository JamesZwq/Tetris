#ifndef PLAYER_H
#define PLAYER_H
#include "Block.h"
#include "helper.h"

#define max_r 22
#define max_c 12
#define max_tetris_size 4
#define background_color 0
#define wall_color 1
#define block_color 2

typedef struct player *Player;
struct player {
    int     score;
    int     max_score;
    int     **Map;
    Block   next_block;
    Block   current_block;
    char    name;
};

Player new_player_info();

void free_player_info(Player player);

int **creat_map();

void print_map(Player user_info);

#endif /* PLAYER_H */
