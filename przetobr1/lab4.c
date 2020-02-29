


int zapisz(FILE *plik_wy, int obrazek[][MAX],int wymx, int wymy, int szarosc){
    int w,k;
    fprintf(plik_wy,"P2\n %d %d \n %d \n",wymx,wymy,szarosc);
    for(w=0;w<wymx;w++){
        for(k=0;k<wymmy;k++){
            fprintf(plikwy,"%d",obrazek[w][k]);
            fprintf(plik_wy,"\n");
        }
        }
return 0
    }
