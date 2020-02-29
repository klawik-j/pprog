#include<stdio.h>
#include<stdlib.h>
#include"modul.h"

/*
int main(){

    int **obraz;
    int wymy,wymx;
    int w,k;

    wymx=10;
    wymy=3;

    obraz= malloc(wymx*sizeof(int*));{
        for(w=0;w<wymy;w++){
            obraz[w]=malloc(wymy+sizeof(int));
        }
    }


for(w=0;w<wymy;w++){
    for(k=0;k<wymx;k++){
        obraz[w][k]=0;
        printf("%d",obraz[w][k]);
    }
    }printf("\n");

    free(obraz);
    return 0;
}

*/




typedef struct{
    int **obraz;
    int wymx,wymy;
}struktura;

int main(){
    int w,k;
    struktura zm;

    zm.wymy=3;
    zm.wymx=10;

  przydziel(&zm);

    

    

for(w=0;w<zm.wymx;w++){
    for(k=0;k< zm.wymy;k++){
        zm.obraz[w][k]=0;
        printf("%d",zm.obraz[w][k]);
    }
    printf("\n");
}
    

    free(zm.obraz);
    return 0;
}







