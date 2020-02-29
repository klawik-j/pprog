#define DL_LINII 80
typedef struct  
{
	int szer;
	int wys;
	int **obraz;
	int odcieni;
} pgm;

int** alok_tab(int wys, int szer);
void zwalnianie(int **a, int wys);
int czytaj(FILE *p, pgm *obraz);
void wyswietl(char *n_pliku);
void wyswietl_tab(pgm *obraz);
int zapisz(FILE *p, pgm *obraz);

