#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Block.h"
#include "helper.h"

void print_map(Player user_info){
    for(int i = 0; i < max_r; i++){
        for(int j = 0; j < max_c; j++){
            printf("%d ", user_info->Map[i][j]);
            if (j == max_c-1){
                //print Player
                if (i == 3 && j == max_c-1){
                    //print score
                    printf("     score: %d", user_info->score);
                }
                else if (i == 2 && j == max_c-1){
                    //print max score
                    printf("     max_score: %d", user_info->max_score);
                }
                else if (i == 1 && j == max_c-1){
                    //print name
                    printf("     player name: %c", user_info->name);
                }
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

Player new_player_info(){
    Player user_info = (Player)malloc(sizeof(Player));
    user_info->score = 0;
    user_info->max_score = 0;
    char user_name;
    printf("please enter your name: ");
    scanf("%c", &user_name);

    // if (strlen(&user_name) > 15){
    //     fprintf(stderr, "name is too long, please enter a shorter name\n");
    // }

    // if (strlen(&user_name) == 0){
    //     fprintf(stderr, "name is empty, please enter a name\n");
    // }

    // if (strcmp(user_name,"\n")){
    //     strcpy(user_name," ");
    // }

    user_info->name = user_name;
    user_info->Map = creat_map();
    user_info->next_block = new_block();
    user_info->current_block = new_block();
    return user_info;
}

void free_player_info(Player user_info){
    free_2d_array(user_info->Map, max_r);
    free_block(user_info->next_block);
    free_block(user_info->current_block);
    free(user_info);
}