#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgmobsluga.h"
#include "filtry.h"
#include <assert.h>




/*funkcja negatyw - od wartosci max szarosci odejmuje sie wartosc komorki i uzyskuje sie obraz w negatywie*/
void negatyw(pgm *obraz)
{
	int i, j;
	assert(obraz->obraz != NULL);
	for(i = 0; i < obraz->wys; i++)
	{
		for(j = 0; j < obraz->szer; j++) 
		{
			obraz->obraz[i][j] = obraz->odcieni - obraz->obraz[i][j];
		}
	}
}


/* dla progu o wartoœci PROG program zamienia wartoœci powy¿ej prog na wartosc skali szarosci a ponizej na kolor czarny*/
void progowanie(pgm *obraz, int prog)
{
	int i, j;
	
	for(i = 0; i < obraz->wys; i++)
	{
		for(j = 0; j < obraz->szer; j++) 
		{
			if (obraz->obraz[i][j] < prog) /*dla wartosci mniejszej od progu*/
				obraz->obraz[i][j] = 0;
			else
				obraz->obraz[i][j] = obraz->odcieni;
		}
	}
}


void splot(pgm *obraz, int splot[3][3])
{
	int a,w,k,i,j;
	int **tab = alok_tab(obraz->wys, obraz->szer);
	if (tab == NULL)
		return;
	
	for(i = 1; i < obraz->wys - 1; i++) 
	{
		for(j = 1; j < obraz->szer - 1; j++) 
		{
			a=0;
			for (w = 0; w < 3; w++)
			{	
				for(k = 0; k < 3; k++)
				{
					a+= obraz->obraz[i - 1 + w][j - 1 + k] * splot[w][k];
				}
			}	
			tab[i][j] = a;	
		}	
	}
			
	for(i = 1; i < obraz->wys - 1; i++) 
	{
		for(j = 1; j < obraz->szer - 1; j++) 
		{
			obraz->obraz[i][j] = tab[i][j];
		}
	}
	zwalnianie(tab, obraz->wys);
}






/*polega na wyostrzeniu kontur obrazu porównuj¹c zawartoœci komórek*/
void konturowanie(pgm *obraz)
{
	int i, j; /* i - wiersze, j - kolumny*/
	for(i = 0; i < obraz->wys - 1; i++) /*"skaczemy" po komowkach zwiekszajac ich numer wiersza o 1*/
	{
		for(j = 0; j < obraz->szer - 1; j++) /* ...i numer kolumny o 1*/
		{
			obraz->obraz[i][j] = abs(obraz->obraz[i+1][j] - obraz->obraz[i][j]) + abs(obraz->obraz[i][j+1] - obraz->obraz[i][j]); /*na ile w danej komórce zmienia siê jasnoœæ, dzia³a na zasadzie porównania zawartisci*/
		}
	}
}
