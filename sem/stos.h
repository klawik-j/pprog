#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef struct etykieta_wezel
{
  int wart;
  struct etykieta_wezel* nast;
} wezel;
 
void push(wezel** stos, int zmienna);
int top(wezel** stos);
void pop(wezel** stos);
int empty(wezel** stos);

