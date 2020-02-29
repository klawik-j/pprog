#define W_OK 0                   /* wartosc oznaczajaca brak bledow */
#define B_NIEPOPRAWNAOPCJA -1   /* kody bledow rozpoznawania opcji */
#define B_BRAKNAZWY   -2
#define B_BRAKWARTOSCI  -3
#define B_BRAKPLIKU   -4

typedef struct 
{
	FILE *plik_we, *plik_wy;        /* uchwyty do pliku wej. i wyj. */
	int negatyw,progowanie,konturowanie,wyswietlenie, splot;      /* opcje */
	int w_progu;              /* wartosc progu dla opcji progowanie */ 
} w_opcje;

void wyzeruj_opcje(w_opcje * wybor);
int przetwarzaj_opcje(int argc, char **argv, w_opcje *wybor);