#ifndef BLOCK_H
#define BLOCK_H

#define block_color 2
#define max_tetris_size 4

typedef struct block *Block;
struct block {
    int     **blo;
    int     **location;
    int     color;
};

Block new_block();

void free_block(Block block);

void print_block(Block block);

void change_block(Block block);

#endif 
