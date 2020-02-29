/*  ----------- PRZEWTARZANIE OBRAZOW 2 ------------ */
/* ************************************************* */
/* Program main.c zawiera w sobie moduly pgmobsluga.h*/
/* oraz filtry.h, ktore kolejno zawieraj¹ funkcje ob-*/
/* slugi zapisu/odczytu/wyswietlenia obrazu oraz  za-*/
/* wiera filtry negatyw/konturowanie/splot/progowanie*/
/*   												     */
/* Program wywo³ujemy podaj¹c parametry :                */
/* -i <nazwa pliku> - otwiera wskazany plik              */
/* -o <nazwa pliku> - zapisuje plik na którym operujemy  */
/*   do pliku <nazwa pliku>                              */
/* -p <prog> - wykonuje progowanie nad wczytanym plikiem */
/* -s - wykonuje splot nad wczytanym plikiem             */
/* -k - wykonuje konturowanie nad wczytanym plikiem      */
/* -n - wykonuje negatyw nad wczytanym plikiem           */
/*   												     */
/*   												     */
/*   np:											     */
/*   	./a.out -i kubus.pgm -p 40	-o pliczek.pgm		 */
/*  zapisuje obraz kubus.pgm nad którym zosta³o wykonane */
/*  progowanie przyjmuj¹c 40 za wartosc progu            */
/*   												     */
/* ***************************************************** */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pgmobsluga.h"
#include "filtry.h"
#include "opcje.h"
#include <assert.h>


int main(int argc, char ** argv) 
{
	
	pgm obraz1;
	int filtr[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
	w_opcje opcje;
	printf("%d\n", przetwarzaj_opcje(argc,argv,&opcje));
	czytaj(opcje.plik_we, &obraz1);
	
	if (opcje.plik_we == NULL || opcje.plik_wy == NULL) 
	{
		return(0);
	}
	if (opcje.progowanie == 1)
		progowanie(&obraz1, opcje.w_progu);
	if (opcje.negatyw == 1)
		negatyw(&obraz1);
	if (opcje.splot == 1)
		splot(&obraz1, filtr);
	if (opcje.konturowanie == 1)
		konturowanie(&obraz1);
	if (opcje.wyswietlenie == 1)
		wyswietl_tab(&obraz1);
	zapisz(opcje.plik_wy, &obraz1);
	return 0;
}
