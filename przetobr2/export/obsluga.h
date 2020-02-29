#define DL_LINII 80


typedef struct{
	int wymx;
	int wymy;
	int odcieni;
    int **obraz;
}pgm;

int** alok(int wymy, int wymx);
void zwolnij(int **a, int wymy);
int czytaj(FILE *p, pgm *obraz);
void wyswietl(char *n_pliku);
int zapisz(FILE *p, pgm *obraz);