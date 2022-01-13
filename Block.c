#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Block.h"
#include "helper.h"

Block new_block(){
    Block block = (Block)malloc(sizeof(struct block));
    block->blo = creat_2d_array(max_tetris_size, max_tetris_size);
    block->location = creat_2d_array(max_tetris_size, max_tetris_size);
    block->color = block_color;
    change_block(block);
    return block;
}

void free_block(Block block){
    free_2d_array(block->blo);
    free_2d_array(block->location);
    free(block);
}

void print_block(Block block){
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            printf("%d ", block->blo[i][j]);
        }
        printf("\n");
    }
}

void change_block(Block block){
    int block_type = rand() % 7;
    int **block_tmp = block->blo;
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            block_tmp[i][j] = 0;
        }
    }
    if (block_type == 0){
        block_tmp[0][0] = block_color;
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color; //I
        block_tmp[0][3] = block_color;
    }
    else 
    if (block_type == 1){
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color;//O
        block_tmp[1][1] = block_color;
        block_tmp[1][2] = block_color;
    }
    else 
    if (block_type == 2){
        block_tmp[0][0] = block_color;
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color;
        block_tmp[1][0] = block_color;//J
    }
    else
    if (block_type == 3){
        block_tmp[0][0] = block_color;
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color;
        block_tmp[1][2] = block_color;//L
    }
    else
    if (block_type == 4){
        block_tmp[0][0] = block_color;
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color;
        block_tmp[1][1] = block_color;//O
    }
    else
    if (block_type == 5){
        block_tmp[0][0] = block_color;
        block_tmp[0][1] = block_color;
        block_tmp[1][1] = block_color;
        block_tmp[1][2] = block_color;//T
    }
    else
    if (block_type == 6){
        block_tmp[0][1] = block_color;
        block_tmp[0][2] = block_color;
        block_tmp[1][0] = block_color;
        block_tmp[1][1] = block_color;//Z
    }
}