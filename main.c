#include <stdio.h>
#include "function.h"

int main() {
    tgame *arr;
    arr=create(7,7);
    print(*arr,7,7);

    int winner=game(*arr);
    if(winner==1){
        printf("White gamer is the winner!!!");
    }else {
        printf("Black player is the winner!!!");
    }



    return 0;
}
