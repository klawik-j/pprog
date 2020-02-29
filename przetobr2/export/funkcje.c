
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"obsluga.h"
#include"funkcje.h"




                     /*/    NEGATYW   /*/
int negatyw(pgm *obraz){
  int w,k;
  for(w=0;w<obraz->wymy;w++){
    for(k=0;k<obraz->wymx;k++)
      obraz->obraz[w][k]=obraz->odcieni - obraz->obraz[w][k];          /* odjecie wartosci od wartosci maxymalnej */
  }
  printf("zrobione\n");
return 0;
}

                      /*/    POLPROGOWANIE CZERI   /*/
int progczerni(pgm *obraz, int prog){
  int w,k;
  for(w=0;w<obraz->wymy;w++){
    for(k=0;k<obraz->wymx;k++)
      if(obraz->obraz[w][k]<= ((obraz->odcieni)*prog)/100)     /* zmienienie wartosci jezeli ta nie przekracza okreslonego progu */
        obraz->obraz[w][k]=0;
      
  }
  printf("zrobione\n");
return 0;
}

            /*/    ROZCIAGNIECIE HISTORGAMU    /*/
int rozhist(pgm *obraz){
  int w,k;
  int lmin=obraz->obraz[0][0];
  int lmax=obraz->obraz[0][0];

  for(w=0;w<obraz->wymy;w++){
    for(k=0;k<obraz->wymx;k++){
      if(obraz->obraz[w][k]>lmax)        /* szukanie wartosci maxymalnej */
      lmax=obraz->obraz[w][k];
      if(obraz->obraz[w][k]<lmin)        /* szukanie wartosci minimalenj */
      lmin=obraz->obraz[w][k];
    }
  }
  for(w=0;w<obraz->wymy;w++){
    for(k=0;k<obraz->wymx;k++)
      obraz->obraz[w][k]=(obraz->odcieni)*(obraz->obraz[w][k]-lmin)/(lmax-lmin);
  }
printf("zrobione\n");
return 0;
}

            /*/   KONTUROWANIE    /*/
int konturowanie(pgm *obraz){
	int w, k; 
	for(w = 0; w < obraz->wymy - 1; w++){
		for(k = 0; k < obraz->wymx - 1; k++){
			obraz->obraz[w][k] = abs(obraz->obraz[w+1][k] - obraz->obraz[w][k]) + abs(obraz->obraz[w][k+1] - obraz->obraz[w][k]);
		}
	}
  printf("zrobione\n");
  return 0;
}