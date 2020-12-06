//
// Created by demen on 20/11/2020.
//

#ifndef DOIT_FUNCTION_H
#define DOIT_FUNCTION_H

#endif //DOIT_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

struct dama{
    int **arr;
};
typedef struct dama  tgame;

int white=0,black=0;
/*
 * 1 = black box
 * 0 = white box
 * 2 = white pawn
 * 3 = black pawn */

tgame* create(int cols,int rows);

void move_white(tgame result, int std_x, int std_y, int arr_x, int arr_y);

void move_black(tgame result, int std_x, int std_y, int arr_x, int arr_y);

void print(tgame result, int rows , int cols);

int convert();

void freegame(tgame *result, int rows);

int game(tgame result);