#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int **creat_2d_array(int row, int col){
    int **array = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++){
        array[i] = (int *)malloc(col * sizeof(int));
    }
    return array;
}

void free_2d_array(int **array){
    for(int i = 0; array[i]; i++){
        printf("%d\n", i);
        free(array[i]);
    }
    free(array);
}
