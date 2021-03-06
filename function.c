#include <stdio.h>
//#include <stdlib.h/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"


void move_white(tgame result, int std_x, int std_y, int arr_x, int arr_y){

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

void move_black(tgame result, int std_x, int std_y, int arr_x, int arr_y){

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




/*
 * 1 = black box
 * 0 = white box
 * 2 = white pawn
 * 3 = black pawn */
void print(tgame result, int rows , int cols){
    printf("%32s","LASKA GAME\n");
    printf("%s%4d\n%s%4d\n\n","Black Point:",black,"White Point:",white);
    printf(" ");
    int i = 0, j = 0;
    for (int i = 0; i < rows; ++i) {
        printf(" %c",65+i);
    }

    i = 0;

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
    int i = 0;
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
        move_white(result,std_x-1,std_y,arr_x-1,arr_y);
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
        move_black(result,std_x-1,std_y,arr_x-1,arr_y);
        print(result,7,7);
    }
    if(white>black){
        return 1;
    }else
        return 0;
}

