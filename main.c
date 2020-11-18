#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct dama{
    int **arr;
};
typedef struct dama  tgame;

tgame* create(int cols,int rows){
    tgame *result;
    int i,j;

    result=(tgame*)malloc(sizeof(tgame));
    assert(result!=NULL);
    result->arr=(int**)malloc(sizeof(int*)*rows);
    assert(result->arr!=NULL);
    for(i=0;i<rows;i++){
        result->arr[i]=(int*)malloc(sizeof(int)*cols);
        assert(result->arr[i]!=NULL);
    }
    for(i=0;i<rows;i++){
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
        for (int l = 0; l <cols ; ++l) {
            if(result->arr[k][l]==0  ){
                if(k>rows/2 && k<=rows) {
                    result->arr[k][l] = 2;
                }else if(k>=0 && k<rows/2){
                    result->arr[k][l] = 3;

                }
            }

        }

    }


    return result;

}
/*
void move_black(tgame result, int rows , int cols, int arr_x, int arr_y, int std_x, int std_y){

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <cols ; ++j) {
            if(result.arr[std_x][std_y]==)

        }

    }


}

*/



/*
 * 1 = black box
 * 0 = white box
 * 2 = white pawn
 * 3 = clack pawn */
void print(tgame result, int rows , int cols){
    printf(" ");
    for (int i = 0; i < rows; ++i) {
        printf(" %c",65+i);
    }
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        printf("%d ",i+1);
        for (int j = 0; j <cols; ++j) {
            if(result.arr[i][j]==0){
                printf("%c ",219);
            }else if(result.arr[i][j]==1){
                printf("%c ",' ');
            }else if(result.arr[i][j]==2){
                printf("%c ",'W');
            }else if(result.arr[i][j]==3){
                printf("%c ",'B');
            }
        }
        printf("\n");

    }
}
int main() {
    tgame *arr;
    arr=create(7,7);
    print(*arr,7,7);


    return 0;
}
