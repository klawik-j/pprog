/* ----------- PRZEWTARZANIE OBRAZOW 2 ------------ */
/* pgmobsluga.c zawiera obsluge  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgmobsluga.h"
#include "filtry.h"





/* ----------------------------- */
/* Alokowanie pamieci na tablice */
/* ----------------------------- */
int** alok_tab(int wys, int szer)
{
	int i;
	int** tmp = NULL;
	tmp = malloc(sizeof(int*)*wys);
	
	if (tmp == NULL)
	{
		fprintf(stderr, "blad alokacji pamieci\n");
		return NULL;
	}
	for (i = 0; i < wys; i++)
	{
		tmp[i] = malloc(sizeof(int)*szer);
		if (tmp[i] == NULL)
		{
			fprintf(stderr, "blad alokacji pamieci\n");
			return NULL;
		}
	}
	return tmp;
}	
 
/* -------------------------- */
/* Zwalnianie pamieci tablicy */
/* -------------------------- */
void zwalnianie(int **a, int wys)
{	
	int i;
	
	for (i = 0; i < wys; i++)
	{
		free(a[i]);
	}
	free(a);
}

/* ---------------------------------- */
/* Odczytywanie modyfikowanego obrazu */
/* ---------------------------------- */
int czytaj(FILE *p, pgm *obraz) 
{
	char s[DL_LINII];
	int znak, koniec = 0, i, j;

	/*sprawdzenie czy podano prawid³owy uchwyt pliku */
	if (p == NULL) 
	{
		fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
		return(0);
	}
	if (fgets(s,DL_LINII,p) == NULL) 
		koniec = 1;
		/* Sprawdzenie "numeru magicznego - powinien byæ P2 */
	if ( (s[0] != 'P') || (s[1] != '2') || koniec) 
	{
		fprintf(stderr,"Blad: To nie jest plik PGM\n");
		return(0);
	}
  /* Pominiecie komentarzy */
	do 
	{
		if ((znak=fgetc(p)) == '#') 
		{
			if(fgets(s,DL_LINII,p) == NULL) 
				koniec=1;
		}  
		else 
		{
			ungetc(znak,p);
		}
	} 
	while (! koniec && znak == '#');

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
	if (fscanf(p,"%d %d %d",&(obraz->szer), &(obraz->wys), &(obraz->odcieni)) != 3) 
	{
		fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
		return(0);
	}      
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm */
	obraz->obraz = alok_tab(obraz->wys, obraz->szer);
	if (obraz->obraz == NULL)
		return 0;
	for (i = 0;i < obraz->wys; i++) 
	{
		for (j = 0;j < obraz->szer; j++) 
		{
			if (fscanf(p,"%d",&(obraz->obraz[i][j])) != 1) 
			{
				fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
				return(0);
			}
		}
	}
	
	return (obraz->szer)*(obraz->wys);
}


/* ------------------------------------ */
/* Wyswietlenie obrazu o zadanej nazwie */
/* za pomoca programu "display".        */
/* ------------------------------------ */
void wyswietl(char *n_pliku) {
  char polecenie[1024];
  strcpy(polecenie,"display ");
  strcat(polecenie,n_pliku);
  strcat(polecenie," &");  
  printf("%s\n",polecenie);
  system(polecenie);
}

/* ------------------------------- */
/* Wyswietlanie tablicy obrazu pgm */
/* ------------------------------- */
void wyswietl_tab(pgm *obraz)
{
	int i, j;
	for(i = 0; i < obraz->wys; i++)
	{
		for(j = 0; j < obraz->szer; j++) 
		{
			printf("%4d", obraz->obraz[i][j]);
		}
		printf("\n"); 
	}
}


/* wyœwietla zapis obrazu pgm wraz ze znakiem magicznym, wymiarami x i y, oraz skal¹ szaroœci*/
int zapisz(FILE *p, pgm *obraz)
{
	int i, j;
	
	if (p==NULL) /*sprawdzanie czy podano prawidlowo wskaznik*/
	{
		fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n"); /* jezei nie to zostaje wyslana informacja do standardowego */
		return(0);
	}
	fprintf(p, "P2\n");
	fprintf(p, "%d %d\n", obraz->szer, obraz->wys);
	fprintf(p, "%d\n", obraz->odcieni);

	
	for(i = 0; i < obraz->wys; i++)
	{
		for(j = 0; j < obraz->szer; j++) 
		{
			fprintf(p, "%3d ", obraz->obraz[i][j]);
		}
		fprintf(p, "\n");
	}
	return 1;
}