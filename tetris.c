#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"
#include "Player.h"

int main(void){
    Player user_info = new_player_info();

    srand(time(NULL)); //reset the random
    print_map(user_info);
    change_block(user_info->next_block);
    //print_block(user_info->next_block);
    printf("\n");
    free_player_info(user_info);
}
