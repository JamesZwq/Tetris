# Makefile for Assignment 2

CC = gcc
CFLAGS = -Wall -Werror -g

all: tetris

tetris: Block.c helper.c Player.c tetris.c
	$(CC) $(CFLAGS) -o tetris Block.c helper.c Player.c tetris.c


clean:
	rm -rf tetris

