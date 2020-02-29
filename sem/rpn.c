
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stos.h"

int main()
{
	wezel* stos = NULL; /*Deklaracja stosu, wskazuj�cego poczatkowo na NULL*/
	int zmienna;
	int i, a, b, c, n = 0; /*zmienne pomocnicze*/
	int tablica_stos[50]; /*Deklaracja pomocniczej tablicy*/
	char temp;
	
	printf("Wpisz dzialanie :\n\n");
	while(temp != 'q') /*Warunek konca - jak wpiszemy q to program konczy dzialanie i otrzymujemy wynik*/
    {
		temp = getc(stdin); /*Pobiera jeden znak ze standardowego wejscia*/
		ungetc(temp, stdin); /*Odklada znak tam gdzie byl, trzyma go w pamieci w zmiennej temp*/
		
		
		/* <<< ZAMIANA ELEMENTOW NA STOSIE >>> */
		if(temp == '$' && !empty(&stos)) 
		{		
			assert(!empty(&stos));
			a = top(&stos); /*odczytuje pierwszy element ze stosu*/
			pop(&stos); /* zdejmuje element ze stosu */
			assert(!empty(&stos));
			b = top(&stos);
			pop(&stos);
			push(&stos, a); /*zamienia miejscami a i b*/
			push(&stos, b);
			getc(stdin); /* pobiera znak (spacje, enter itp)*/
		}
		
		/* <<< ZDUBLOWANIE ELEMENTU NA STOSIE >>> */
		else if(temp == '&' && !empty(&stos))
		{
			zmienna = top(&stos); /*odczytuje pierwszy element ze stosu*/
			push(&stos, zmienna); /*kladzie go na stos*/
			n++;/*zwieksza liczbe elementow*/
			getc(stdin);
		}
		
		/* <<< USUWANIE ELEMENTU ZE STOSU >>> */
		else if(temp == '#' && !empty(&stos))
		{
			pop(&stos);
			n--; /*zmniejsza liczbe elementow*/
			getc(stdin);
		}
		
		/* <<< WYPISANIE ELEMENTOW STOSU >>> */
		else if(temp == '?' && !empty(&stos))
		{
			printf("\nELEMENTY STOSU:\n");
			for(i = 0; i < n; i++)
			{
				a = tablica_stos[i] = top(&stos); /*Przypisuje do pierwszego elementu tablicy wartosc z gory stosu*/
				if(a == '+' || a == '*' || a == '/' || a == '-' )
				{ /* Jezeli a jest znakiem to wyswietla znak */
					printf("\n    %c", a);
				}
				else
				{ /* Jezeli a jest liczba to drukuje liczbe */
					printf("\n    %d", a);
				}
			pop(&stos); /* zdejmuje element ze stosu*/ 
			}
			for(i = n - 1; i >= 0; i--)
			{
				a = tablica_stos[i]; /* z powrotem uklada elementy na stosie */
				push(&stos, a);
			}
			getc(stdin);
			printf("\n\n\n");
		}  
		else if(temp == 32 || temp == 10) /* sprawdza znaki spacji i entera*/
		{
			temp=getc(stdin); 
		} 
		else if(temp <= '9' && temp >= '0' && temp != 'q') /*jezeli temp jest cyfra to wczytuje liczbe*/
		{
			scanf("%d", &zmienna);/*wczytuje*/ 
			push(&stos, zmienna);/*kladzie liczbe na stos*/
			n++; /*zwieksza liczbe elementow o 1*/
		}
		if(temp=='-')
		{
			getc(stdin);
			temp = getc(stdin);
			if(temp <= '9' && temp >= '0') /* sprawdza czy temp to cyfra */
			{
				ungetc(temp, stdin);  /* odklada temp na wejscie */
				scanf("%d", &zmienna);  /* wczytuje liczbe jako liczbe */
				zmienna=zmienna*(-1);   /*mnozy ta liczbe razy -1 bo nie odczytuje juz minusa*/
				push(&stos, zmienna);   /*odklada liczbe z powrotem na stos*/   
				n++;
			}
			else /*jesli nie jest cyfra*/
			{
				assert(empty(&stos) == 0); /*jesli nie jest stos pusty*/
				a = top(&stos); /* czyta ze stosu pierwszy element*/
				pop(&stos); /* zdejmuje ten element*/
				assert(empty(&stos) == 0);
				b = top(&stos);
				pop(&stos);
				c = b - a;
				push(&stos, c); /* kladzie na stosie wynik */	
				n--;/*zmniejsza liczbe elementow o 1 poniewaz wykonal dzialanie na 2 liczbach */
			}
		}
		if((temp == '+' || temp == '*' || temp == '/') && temp != 'q') /* jezeli zostalo wprowadzone jakies dzialanie*/
		{
			assert(empty(&stos) == 0);
			a = top(&stos);
			pop(&stos);
			assert(empty(&stos) == 0);
			b = top(&stos);
			pop(&stos);
			
			
			switch(temp) /*wykonuje oczywiste dzialania*/
			{
				case '+':
					c = a + b;
				break;
			  
				case '*':
					c = a * b;
				break;
			  
				case '/':
					c = b / a;
				break;
			} 
			push(&stos, c); /*kladzie wynik na stos*/
			n--;
			getc(stdin); /*wczytuje spacje, czy tam enter*/
		}
    }
	for(i = 1; ; i++)
    {
		if(!top(&stos)) /*jesli stos jest pusty to wychodzi z petli*/
			break;
		zmienna = top(&stos);
		printf("%d: %d\n", i, zmienna); /*wypisuje wszystko*/
		pop(&stos);
    }
  return 0;
}
