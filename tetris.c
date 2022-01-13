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
    char    name;
};

	

int **creat_map();
void print_map(Info user_info); 
void creat_block(Info user_info);
void free_info(Info user_info);
Info new_player_info();
void print_next_block(Info user_info);
void change_block(Info user_info);


int main(void){
    Info user_info = new_player_info();

    srand(time(NULL));
    print_map(user_info);
    creat_block(user_info);
    print_next_block(user_info);

    creat_block(user_info);
    print_next_block(user_info);

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
    int **Map = malloc(max_r*sizeof(int *));
    for(int i = 0; i < max_r; i++){
        Map[i] = malloc(sizeof(int*) * max_c);
    }
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
    user_info->next_block = NULL;
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

    free(user_info);
}

void creat_block(Info user_info){
    int **block = malloc(max_tetris_size * sizeof(int **));
    for(int i = 0; i < max_tetris_size; i++){
        block[i] = malloc(sizeof(int*) * max_tetris_size);
    }
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            block[i][j] = 0;
        }
    }
    change_block(user_info);
}

void print_next_block(Info user_info){
    for(int i = 0; i < max_tetris_size; i++){
        for(int j = 0; j < max_tetris_size; j++){
            printf("%d ", user_info->next_block[i][j]);
        }
        printf("\n");
    }
}

void change_block(Info user_info){
    int **block = user_info->next_block;
    int block_type = rand() % 7;
    printf("112312123122\n");
    printf("block_type: %d\n", block_type);
    printf("123123");
    if (block_type == 0){
        block[0][0] = 1;
        block[0][1] = 1;
        block[0][2] = 1; //I
        block[0][3] = 1;
    }
    else 
    if (block_type == 1){
        block[0][1] = 1;
        block[0][2] = 1;//S
        block[1][1] = 1;
        block[1][2] = 1;
    }
    else 
    if (block_type == 2){
        block[0][0] = 1;
        block[0][1] = 1;
        block[0][2] = 1;
        block[0][1] = 1;//J
    }
    else
    if (block_type == 3){
        block[0][0] = 1;
        block[0][1] = 1;
        block[0][2] = 1;
        block[1][2] = 1;//L
    }
    else
    if (block_type == 4){
        block[0][0] = 1;
        block[0][1] = 1;
        block[1][0] = 1;
        block[1][1] = 1;//O
    }
    else
    if (block_type == 5){
        block[0][0] = 1;
        block[0][1] = 1;
        block[1][0] = 1;
        block[1][1] = 1;
        block[1][2] = 1;//T
    }
    else
    if (block_type == 6){
        block[0][0] = 1;
        block[0][1] = 1;
        block[1][0] = 1;
        block[1][1] = 1;
        block[1][2] = 1;
        block[2][0] = 1;
        block[2][1] = 1;//Z
    }
}