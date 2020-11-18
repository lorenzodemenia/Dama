#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
struct dama{
    int **arr;
};
typedef struct dama  tgame;

int white=0,black=0;


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
void move_white(tgame result, int rows, int cols , int std_x, int std_y, int arr_x, int arr_y){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(result.arr[std_x][std_y]==2 && result.arr[arr_x][arr_y]==0){
                result.arr[std_x][std_y]=0;
                result.arr[arr_x][arr_y]=2;
            }else if(result.arr[std_x][std_y]==2 && result.arr[arr_x][arr_y]==3){
                if(result.arr[arr_x-1][arr_y+1]==0 && result.arr[arr_x-1][arr_y-1]!=0){
                    white++;
                    result.arr[std_x][std_y]=0;
                    result.arr[arr_x][arr_y]=0;
                    result.arr[arr_x-1][arr_y+1]=2;
                }else if(result.arr[arr_x-1][arr_y+1]!=0 && result.arr[arr_x-1][arr_y-1]==0){
                    white++;
                    result.arr[std_x][std_y]=0;
                    result.arr[arr_x][arr_y]=0;
                    result.arr[arr_x-1][arr_y-1]=2;
                }else if(result.arr[arr_x-1][arr_y+1]!=0 && result.arr[arr_x-1][arr_y-1]!=0){
                    srand(time(NULL));
                    int rnd= rand()%2;
                    if(rnd==0){
                        white++;
                        result.arr[std_x][std_y]=0;
                        result.arr[arr_x][arr_y]=0;
                        result.arr[arr_x-1][arr_y-1]=2;
                    }else {
                        white++;
                        result.arr[std_x][std_y]=0;
                        result.arr[arr_x][arr_y]=0;
                        result.arr[arr_x-1][arr_y+1]=2;
                    }
                }
            }
        }
    }
}

void move_black(tgame result, int rows, int cols , int std_x, int std_y, int arr_x, int arr_y){

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <cols ; ++j) {
            if(result.arr[std_x][std_y]==3 && result.arr[arr_x][arr_y]==0 ){
                result.arr[std_x][std_y]=0;
                result.arr[arr_x][arr_y]=3;
            }else if(result.arr[std_x][std_y]==3 && result.arr[arr_x][arr_y]==2){
                if(result.arr[arr_x+1][arr_y+1]==0 && result.arr[arr_x+1][arr_y-1]!=0){
                    black++;
                    result.arr[std_x][std_y]=0;
                    result.arr[arr_x][arr_y]=0;
                    result.arr[arr_x+1][arr_y+1]=3;
                }else if(result.arr[arr_x+1][arr_y-1]==0 && result.arr[arr_x+1][arr_y+1]!=0){
                    black++;
                    result.arr[std_x][std_y]=0;
                    result.arr[arr_x][arr_y]=0;
                    result.arr[arr_x+1][arr_y-1]=3;
                }else if (result.arr[arr_x+1][arr_y+1]==0 && result.arr[arr_x+1][arr_y-1]==0 ){
                    srand(time(NULL));
                    int rnd= rand()%2;
                    if(rnd==0){
                        black++;
                        result.arr[std_x][std_y]=0;
                        result.arr[arr_x][arr_y]=0;
                        result.arr[arr_x+1][arr_y-1]=3;
                    }else {
                        black++;
                        result.arr[std_x][std_y]=0;
                        result.arr[arr_x][arr_y]=0;
                        result.arr[arr_x+1][arr_y+1]=3;
                    }
                }
            }

        }

    }


}




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
int convert(){
    char a;
    int i;
    scanf("%c",&a);
    if(a>='A' && a<='G'){
        return i=a-65;
    }else if(a>='a' && a<='g'){
        return i=a-97;
    } else{
        convert();
    }
}
int game(tgame result){
    int arr_x,arr_y,std_x,std_y;
    while(black!=12 || white!=12){
        printf("Write the coordinate of white pawn\n");
        printf("X:");
        scanf("%d",&std_x);
        printf("Y:");
        std_y=convert();
        printf("\n");
        printf("Write the coordinate of white box to go\n");
        printf("X:");
        scanf("%d",&arr_x);
        printf("Y:");
        arr_y=convert();
        printf("\n");
        move_white(result,7,7,std_x-1,std_y,arr_x-1,arr_y);
        print(result,7,7);
        printf("Write the coordinate of black pawn\n");
        printf("X:");
        scanf("%d",&std_x);
        printf("Y:");
        std_y=convert();
        printf("\n");
        printf("Write the coordinate of white box to go\n");
        printf("X:");
        scanf("%d",&arr_x);
        printf("Y:");
        arr_y=convert();
        printf("\n");
        move_black(result,7,7,std_x-1,std_y,arr_x-1,arr_y);
        print(result,7,7);
    }
    if(white>black){
        return 1;
    }else
        return 0;
}
int main() {
    tgame *arr;
    arr=create(7,7);
    print(*arr,7,7);

    int winner=game(*arr);
    if(winner==1){
        printf("White gamer is the winner!!!");
    }else {
        printf("Black player is the winner!!");
    }



    return 0;
}
