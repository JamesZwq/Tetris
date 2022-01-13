#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max_r 22
#define max_c 12
#define max_tetris_size 4
#define background_color 0
#define wall_color 1
#define block_color 2

typedef struct info *Info;
struct info {
    int     score;
    int     max_score;
    int     **Map;
    int     **next_block;
    int     **current_block;
    int     **current_block_location;
    char    name;
};

	

int **creat_map();
void print_map(Info user_info); 
int **creat_block();
void free_info(Info user_info);
Info new_player_info();
void print_next_block(Info user_info);
void change_block(Info user_info, int type);
int **creat_2d_array(int row, int col);


int main(void){
    Info user_info = new_player_info();

    srand(time(NULL)); //reset the random
    print_map(user_info);
    change_block(user_info,1);
    //print_next_block(user_info);
    printf("\n");
    free_info(user_info);
}

void print_map(Info user_info){
    for(int i = 0; i < max_r; i++){
        for(int j = 0; j < max_c; j++){
            printf("%d ", user_info->Map[i][j]);
            if (i == 3 && j == max_c-1){
                printf("     score: %d", user_info->score);
            }
            if (i == 2 && j == max_c-1){
                printf("     max_score: %d", user_info->max_score);
            }
        }
        printf("\n");
    }
}

int **creat_map(){
    int **Map = creat_2d_array(max_r, max_c);
    for(int i = 0; i < max_r; i++){
        if (i == 0){
            for(int j = 0; j < max_c; j++){
                Map[i][j] = wall_color;
            }
        }
        else if (i == max_r - 1){
            for(int j = 0; j < max_c; j++){
                Map[i][j] = wall_color;
            }
        }
        else{
            for(int j = 0; j < max_c; j++){
                if (j == 0 || j == max_c - 1){
                    Map[i][j] = wall_color;
                }
                else{
                    Map[i][j] = background_color;
                }
            }
        }
    }
    return Map;
}

Info new_player_info(){
    Info user_info = (Info)malloc(sizeof(struct info));
    user_info->score = 0;
    user_info->max_score = 0;
    char user_name;
    printf("please enter your name: ");
    scanf("%c", &user_name);
    user_info->name = user_name;
    user_info->Map = creat_map();
    user_info->next_block = creat_block();
    user_info->current_block = creat_block();
    change_block(user_info,1); //set block
    change_block(user_info,2);
    return user_info;
}

void free_info(Info user_info){

    for (int j = 0; j < max_c; j++){
        free(user_info->Map[j]);
    }
    free(user_info->Map);

    for (int i = 0; i < max_tetris_size; i++){
        free(user_info->next_block[i]);
    }
    free(user_info->next_block);

    for (int i = 0; i < max_tetris_size; i++){
        free(user_info->current_block[i]);
    }
    free(user_info->current_block);

    free(user_info);
}

int **creat_block(){
    return creat_2d_array(max_tetris_size, max_tetris_size);
}

int **creat_2d_array(int row, int col){
    int **array = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        array[i] = (int *)malloc(col * sizeof(int));
    }
    return array;
}

void print_next_block(Info user_info){
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            printf("%d ", user_info->next_block[i][j]);
        }
        printf("\n");
    }
}

void change_block(Info user_info, int type){
    /*
    type = 1, change to next block
    type = 2, change to current block
    */
    int **block = type == 1 ? user_info->next_block : user_info->current_block;
    int block_type = rand() % 7;
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            block[i][j] = 0;
        }
    }
    if (block_type == 0){
        block[0][0] = 1;
        block[0][1] = 1;
        block[0][2] = 1; //I
        block[0][3] = 1;
    }
    else 
    if (block_type == 1){
        block[0][1] = block_color;
        block[0][2] = block_color;//O
        block[1][1] = block_color;
        block[1][2] = block_color;
    }
    else 
    if (block_type == 2){
        block[0][0] = block_color;
        block[0][1] = block_color;
        block[0][2] = block_color;
        block[1][0] = block_color;//J
    }
    else
    if (block_type == 3){
        block[0][0] = block_color;
        block[0][1] = block_color;
        block[0][2] = block_color;
        block[1][2] = block_color;//L
    }
    else
    if (block_type == 4){
        block[0][0] = block_color;
        block[0][1] = block_color;
        block[0][2] = block_color;
        block[1][1] = block_color;//O
    }
    else
    if (block_type == 5){
        block[0][0] = block_color;
        block[0][1] = block_color;
        block[1][1] = block_color;
        block[1][2] = block_color;//T
    }
    else
    if (block_type == 6){
        block[0][1] = 1;
        block[0][2] = 1;
        block[1][0] = 1;
        block[1][1] = 1;//Z
    }
}