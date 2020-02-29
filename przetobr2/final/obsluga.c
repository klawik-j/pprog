#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obsluga.h"
#include "funkcje.h"


/* ########## ALOKOWANIE PAMIECI ########## */
int **alok(int wymy,int wymx){
    int i;
    int **temp=NULL;

    temp=malloc(sizeof(int*)*wymy);

    if(temp==NULL){
        fprintf(stderr,"alokacja pamieci zakonczona niepowodzeniem\n");
        return NULL;
    }

    for(i=0;i<wymy;i++){
        temp[i]=malloc(sizeof(int*)*wymx);
        if(temp[i]==NULL){
            fprintf(stderr, "alokacja pamieci zakonczona niepowodzeniem\n");
            return NULL;
        }
    }
    return temp;
}

/* ########## ZWALNIANIE PAMIECI ########## */
void zwolnij(int **a,int wymy){
    int i;

    for(i=0;i<wymy;i++){
        free(a[i]);
    }
    free(a);
}

/* ########## WCZYTANIE OBRAZU ########## */
int czytaj(FILE *p, pgm *obraz) 
{
	char s[DL_LINII];
	int znak, w, k;
    int koniec = 0;

	
	if (p == NULL) 
	{
		fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
		return(0);
	}
	if (fgets(s,DL_LINII,p) == NULL) 
		koniec = 1;
		
	if ( (s[0] != 'P') || (s[1] != '2') || koniec) 
	{
		fprintf(stderr,"Blad: To nie jest plik PGM\n");
		return(0);
	}
  
	do {
		if ((znak=fgetc(p)) == '#') {
			if(fgets(s,DL_LINII,p) == NULL) 
				koniec=1;
		}  
		else {
			ungetc(znak,p);
		}
	} 
	while (! koniec && znak == '#');

  
	if (fscanf(p,"%d %d %d",&(obraz->wymx), &(obraz->wymy), &(obraz->odcieni)) != 3){        /* Pobranie wymiarow obrazu i liczby odcieni funkcjei */
		fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni funkcjei\n");
		return(0);
	}      
  
	obraz->obraz = alok(obraz->wymy, obraz->wymx);       /* Pobranie obrazu i zapisanie w tablicy obraz_pgm */
	if (obraz->obraz == NULL)
		return 0;
	for (w = 0;w < obraz->wymy; w++){
		for (k = 0;k < obraz->wymx; k++){
			if (fscanf(p,"%d",&(obraz->obraz[w][k])) != 1) {
				fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
				return(0);
			}
		}
	}
	
	return (obraz->wymx)*(obraz->wymy);
}

/* ########## WYSWIETLENIE WCZYTANEGO OBRAZU ########## */
void wyswietl(char *n_pliku){
  char polecenie[1024];
  strcpy(polecenie,"display ");
  strcat(polecenie,n_pliku);
  strcat(polecenie," &");  
  printf("%s\n",polecenie);
  system(polecenie);
}

/* ########## ZAPIS OBRAZU ########## */
int zapisz(FILE *p, pgm *obraz){
	int w, k;
	
	if (p==NULL){
		fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n"); 
		return(0);
	}
	fprintf(p, "P2\n");
	fprintf(p, "%d %d\n", obraz->wymx, obraz->wymy);
	fprintf(p, "%d\n", obraz->odcieni);

	
	for(w = 0; w < obraz->wymy; w++){
		for(k = 0; k < obraz->wymx; k++){
			fprintf(p, "%3d ", obraz->obraz[w][k]);
		}
		fprintf(p, "\n");
	}
	return 0;
}
