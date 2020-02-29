#include "stos.h"

 
void push(wezel** stos, int zmienna)
{
	wezel* nowy;
	nowy = (wezel*)malloc(sizeof(wezel));
	nowy->wart = zmienna;
  
	if(*stos)
    {
		nowy->nast = *stos;
    }
	else
    {
		nowy->nast = 0;
    }
	*stos = nowy;
}

int top(wezel** stos)
{
	int zwracana;
	if(*stos)
    {
		zwracana = (*stos)->wart;
		return zwracana;
    }
	return 0;
}

void pop(wezel** stos)
{
	if(stos)
    {
		wezel* wsk;
		wsk = *stos;
		*stos = (*stos)->nast;
		free(wsk);
    }
}

int empty(wezel** stos)
{
	return !(*stos);
}


