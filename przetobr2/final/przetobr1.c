#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 900            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */

/////////////////////////////



////////////////////////////

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;

  /*Sprawdzenie czy podano prawid³owy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien byæ P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
    fprintf(stderr,"Blad: To nie jest plik PGM\n");
    return(0);
  }

  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
	koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (znak=='#' && !koniec);   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
  if (fscanf(plik_we,"%d %d %d",wymx,wymy,szarosci)!=3) {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<*wymy;i++) {
    for (j=0;j<*wymx;j++) {
      if (fscanf(plik_we,"%d",&(obraz_pgm[i][j]))!=1) {
	fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
	return(0);
      }
    }
  }
  return *wymx**wymy;   /* Czytanie zakonczone sukcesem    */
}                       /* Zwroc liczbe wczytanych pikseli */

/*/////////////////////////////////////////////////////////////////////////////////////////////////////*/
                      /*/    ZAPIS   /*/
int zapisz(FILE *plik_wy, int obraz[][MAX],int wymx, int wymy, int szarosc){
    int w,k;
    fprintf(plik_wy,"P2\n %d %d \n %d \n",wymx,wymy,szarosc);     /*/ wpisanie nr magicznego i rozmiarow obrazu */
    for(w=0;w<wymy;w++){                                          /* przejscie po wierszach */
        for(k=0;k<wymx;k++){                                      /* przejscie po kolumnach */
            fprintf(plik_wy,"%d",obraz[w][k]);                    /*/ wpisanie calej reszty */
            fprintf(plik_wy,"\n");
        }
       
        }
return 0;
    }

                      /*/    NEGATYW   /*/
int negatyw(int obraz[][MAX],int *wymx,int *wymy,int szarosc){
  int w,k;
  for(w=0;w<*wymy;w++){
    for(k=0;k<*wymx;k++)
      obraz[w][k]=szarosc-obraz[w][k];          /* odjecie wartosci od wartosci maxymalnej */
  }
  printf("zrobione\n");
return 0;
}

                      /*/    POLPROGOWANIE CZERI   /*/
int progczerni(int obraz[][MAX],int *wymx,int *wymy,int *szarosc,int prog){
  int w,k;
  for(w=0;w<*wymy;w++){
    for(k=0;k<*wymx;k++)
      if(obraz[w][k]<= ((*szarosc)*prog)/100)     /* zmienienie wartosci jezeli ta nie przekracza okreslonego progu */
        obraz[w][k]=0;
      
  }
  printf("zrobione\n");
return 0;
}
                      /*/    ROZMYCIE PIONOWE    /*/
int rozmycie(int obraz[][MAX],int *wymx,int *wymy,int a){
  int w,k;
  int c;                  /* licznik */
  int obraz2[MAX][MAX];       /* tabela pomocnicza */
  
  for(w=0;w<*wymy;w++){          /* wyzerowanie tabeli pomocniczej */
    for(k=0;k<*wymx;k++){
      obraz2[w][k]=0;
    }
  }    
  
  
  
  for(w=0;w< *wymy;w++){
    for(k=0;k<*wymx;k++){
      if(w-a<0){                   /* jezeli wiersz gorny NIE miesci sie w zakresie pixeli rozmycia */
        for(c=0;c<=a;c++){      /* sumowanie wartosci pixeli ponizej */
          obraz2[w][k]=obraz2[w][k]+obraz[w+c][k];
        }
        for(c=1;c<=w;c++){      /* sumowanie wartosci pixeli powyzej */
          obraz2[w][k]=obraz2[w][k]+obraz[w-c][k];    
        }
        obraz2[w][k]=obraz2[w][k]/(a+a+1);    /* wyciagniecie sredniej  */    
      }
      
      else if(w+a>=*wymy){       /* jezeli wiersz dolny NIE miesci sie w zakresie pixeli rozmycia */
        for(c=0;c<=a;c++){      /* sumowanie pixeli powyzej */
          obraz2[w][k]=obraz2[w][k]+obraz[w-c][k];
        }
        for(c=1;c<=(*wymy-w-1);c++){      /* sumowanie pixeli ponizej */
          obraz2[w][k]=obraz2[w][k]+obraz[w+c][k];    
        }
        obraz2[w][k]=obraz2[w][k]/(a+a+1);    /* wyciagniecie sredniej  */    
      }

      else{         /* jezeli wiersz MIESCI sie w zakresie pixeli rozmycia */
        for(c=0;c<=a;c++){        /* suma */
        obraz2[w][k]=obraz2[w][k]+obraz[w+c][k]+obraz[w-c][k];
        }
        obraz2[w][k]=obraz2[w][k]/(c+c+1);      /* usrednienie */
      }        
      }     
    }
   for(w=0;w<*wymy;w++){          /* przepisanie wartosci z tabeli pomocniczej do tabeli wyjsciowej */
    for(k=0;k<*wymx;k++){
      obraz[w][k]=obraz2[w][k];
    }
   }
  printf("zrobione\n");
  return 0;
}
                      /*/    ROZCIAGNIECIE HISTORGAMU    /*/
int rozhist(int obraz[][MAX],int *wymx,int *wymy,int *szarosc){
  int w,k;
  int lmin=obraz[0][0];
  int lmax=obraz[0][0];

  for(w=0;w<*wymy;w++){
    for(k=0;k<*wymx;k++){
      if(obraz[w][k]>lmax)        /* szukanie wartosci maxymalnej */
      lmax=obraz[w][k];
      if(obraz[w][k]<lmin)        /* szukanie wartosci minimalenj */
      lmin=obraz[w][k];
    }
  }
  for(w=0;w<*wymy;w++){
    for(k=0;k<*wymx;k++)
      obraz[w][k]=(*szarosc)*(obraz[w][k]-lmin)/(lmax-lmin);
  }
printf("zrobione\n");
return 0;
}

/* wyswietlenie obrazu o zadanej nazwie za pomoca programu "display"   */
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}


int main() {
  int obraz[MAX][MAX] ;
  int wymx,wymy,odcieni,prog;
  int a;  /* liczba pixeli do funkcji "rozmycie" */
  


  FILE *plik;
  FILE *plik_wy;    /* plik uzywany do zapisu */
  FILE *plik_tm;    /* plik uzywany w funkcji "rozmycie" */
  char nazwa[100];
  char nazwa_wy[100];
  char nazwa_tm[100]="pliktm.pgm";

  int m=0;  /* menu */

 

  

  

 
 
/*//////////////////////////////////////////////////////////////////////////////*/
              /*/    MENU    /*/
  while(m!=8){
  printf("############  MENU  ########## \n");
  printf("1.Wczytaj\n");
  printf("2.Negatyw\n");
  printf("3.Polprogowanie czerni\n");
  printf("4.Rozmycie pionowe\n");
  printf("5.Rozciagniecie histogramu\n");
  printf("6.wyswietl\n");
  printf("7.Zapisz\n");
  printf("8.Koniec\n");
  printf("############################## \n");
  printf("Twoj wybor:\n");

  scanf("%d",&m);
  switch (m)
  {
    case 1: /*/WCZYTAJ/*/
       /* Wczytanie zawartosci wskazanego pliku do pamieci */
      printf("Podaj nazwe pliku:\n");
      scanf("%s",nazwa);
      plik=fopen(nazwa,"r");

      if (plik != NULL) {       /* co spowoduje zakomentowanie tego warunku */
      czytaj(plik,obraz,&wymx,&wymy,&odcieni);
      fclose(plik);
      }
    break;

    case 2: /*/NEGATYW/*/
      negatyw(obraz,&wymx,&wymy,odcieni);
    break;

    case 3: /*/POLPROGOWANIE CZERNI/*/
      printf("wprowadz procent progowania jako liczbe calkowita z zakresu 0-100:\n");
      scanf("%d",&prog);
      progczerni(obraz,&wymx,&wymy,&odcieni,prog);
    break;

    case 4: /*/ROZMYCIE PIONOWE/*/
      printf("wprowadz liczbe pixeli o ile obraz ma zostac rozmyty:\n");
      scanf("%d",&a);
      rozmycie(obraz,&wymx,&wymy,a);
    break;

    case 5: /*/ROZCIAGNIECIE HISTOGRAMU/*/
    rozhist(obraz,&wymx,&wymy,&odcieni);
    break;

    case 6: /*/wyswIETL/*/
      /* wyswietlenie poprawnie wczytanego obraza zewnetrznym programem */
      plik_tm=fopen(nazwa_tm,"w");
      zapisz(plik_tm,obraz,wymx,wymy,odcieni);
      fclose(plik_tm);
      wyswietl(nazwa_tm);


    break;

    case 7: /*/ZAPISZ/*/
      /* Zapisanie obraza do pliku */
      printf("podaj nazwe pliku do zapisania:\n");
      scanf("%s",nazwa_wy);
      plik_wy=fopen(nazwa_wy,"w");
      zapisz(plik_wy,obraz,wymx,wymy,odcieni);
      fclose(plik_wy);
    break;

    case 8:
      printf("Koniec dzialania programu\n");
      plik_tm=remove(nazwa_tm);       /* Usuniecie pliku tymczasowego z funkcji "wyswietl" */
    break;
  }

  }

  


 return 0;


}