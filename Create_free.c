#include "function.h"

tgame* create(int cols,int rows){
    tgame *result;
    int i = 0, j = 0, k = 0, l = 0;

    result=(tgame*)malloc(sizeof(tgame));
    assert(result!=NULL);

    result->arr=(int**)malloc(sizeof(int*)*rows);
    assert(result->arr!=NULL);

    for(i=0;i<rows;i++){
        result->arr[i]=(int*)malloc(sizeof(int)*cols);
        assert(result->arr[i]!=NULL);
    }
    i = 0;
    for(i = 0;i<rows;i++){
        for(j=0;j<cols;j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                result->arr[i][j] = 0;
            } else if (i % 2 != 0 && j % 2 != 0) {
                result->arr[i][j] = 0;
            } else {
                result->arr[i][j] = 1;
            }
        }
    }
    for (int k = 0; k <rows ; ++k) {
        for (int l = 0; l < cols; ++l) {
            if (result->arr[k][l] == 0) {
                if (k > rows / 2 && k <= rows) {
                    result->arr[k][l] = 2;
                } else if (k >= 0 && k < rows / 2) {
                    result->arr[k][l] = 3;
                }
            }

        }
    }


    return result;
}

void freegame(tgame *result, int rows) {
    int i = 0;

    for(i = 0; i<rows; i++){
        free(result->arr[i]);
    }

    free(result->arr);
    free(result);
}