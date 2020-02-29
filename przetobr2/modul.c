#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int **obraz;
    int wymx,wymy;
}struktura;

void przydziel(struktura *zm){
    int i;

    zm->obraz=malloc(zm->wymx*sizeof(int*));
        for(int i=0;i<zm->wymx;i++){
            zm->obraz[i]=malloc(zm->wymy*sizeof(int));
        }

}

