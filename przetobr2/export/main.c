/* UWAGA-	wedlug polecenia, ktore mowi "Brak opcji -o oznacza wypisanie obrazu na standardowym wyjściu."
			moze dojsc do sytuacji w ktorej uzyjemy opcji -d i NIE uzyjemy opcji -o. Skutkiem tego obraz
			wlasciwie przetworzony zostanie jednoczesnie wypisany na standardowe wyjsci i wyswietlony.


/* ##############################################################################
#	Wyywolanie programu:																	#
#	-i [nazwa pliku]	-wczytanie pliku													#
#	-o [nazwa pliku]	-zapisuje przetworzony plik pod kontretna nazwa						#
#	-d					-wyswietlenie aktualnie przetwarzanego obrazu wraz z zmianami		#
#	-p [prog]			-progowanie												#
#	-n					-negatyw												#
#	-h					-rozciagniecie histogramu								#
#	-k					-konturowanie											#
#################################################################################*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obsluga.h"
#include "funkcje.h"
#include "opcje.h"
#include <assert.h>

int main(int argc, char ** argv) 
{
	FILE *plik_tm;							/* potrzebne do wyswietlenia przetwarzanego obrazu */
	char nazwa_tm[20]="plik_tm.pgm";		/* potrzebne do wyswietlenia przetwarzanego obrazu */
	pgm obraz;
	w_opcje opcje;
	printf("%d\n", przetwarzaj_opcje(argc,argv,&opcje));
	czytaj(opcje.plik_we, &obraz);
	
	if(opcje.plik_we == NULL || opcje.plik_wy == NULL){
		return 0;
	}
	if(opcje.progowanie == 1)
		progczerni(&obraz, opcje.w_progu);
	if(opcje.negatyw == 1)
		negatyw(&obraz);
    if(opcje.rozhist == 1)
    	rozhist(&obraz);
	if(opcje.konturowanie == 1)
		konturowanie(&obraz);
	if(opcje.wyswietlenie == 1){
		plik_tm=fopen(nazwa_tm,"w");
		zapisz(plik_tm, &obraz);
		fclose(plik_tm);
		wyswietl(nazwa_tm);	
	}

	
	zapisz(opcje.plik_wy, &obraz);
	return 0;
}



