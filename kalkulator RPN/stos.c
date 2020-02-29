#include<stdio.h>
#include<stdlib.h>

//definicja typu
typedef struct elem{
  int dana;
  struct elem *nast;
}t_elem,*t_stos;

//funkcja inicjująca
void inicjuj(t_stos *S){
  *S=NULL;
}

//dodatkowo funkcja tworząca element listy
int tworz(t_elem **elem, int dana){
  *elem=(t_elem*)malloc(sizeof(t_elem));
  if(!(*elem))return 1;
  (*elem)->dana=dana;
  (*elem)->nast=NULL;
  return 0;
}

//funkcja wrzucająca na stos
//zwraca 0 kiedy uda się położyć daną na stos - 1 w przeciwnym przypadku
int push(t_stos *S, int dana){
  t_elem *tmp;
  if(tworz(&tmp,dana))return 1;
  tmp->nast=*S;
  *S=tmp;
  return 0;
}

//funkcja usuwająca ze stosu
//dodatkowo zwraca 1 jeżeli stos jest PUSTY lub 0 jeśli wykona się poprawnie 
int pop(t_stos *S, int *dana){
  t_elem *tmp;
  if(!(*S))return 1;
  *dana = (*S)->dana;
  tmp=*S;
  *S=(*S)->nast;
  free(tmp);
  return 0;
}

//funkcja drukująca zawartość stosu
//dla X==1 tylko wierzchołek
//dla X==0 cały stos
//dodatkowo zwraca 1 jeśli stos jest pusty i 0 jeśli wykona się poprawnie
int druk(t_stos S,int X){
  if(S==NULL)return 1;
  while(S){
    printf("### %d\n",S->dana);
    S=S->nast;
    if(X)break;
  }
  return 0;
}

int main(){

  int dana=0;
  t_stos S;
  char a,b;
  int a1,b1,c;
 /* 
  inicjuj(&S);
  push(&S,3);
  push(&S,2);
  druk(S,0);
  pop(&S,&dana);
  druk(S,0);
  pop(&S,&dana);

  return 0;
}
*/

while(a=!'q'){

inicjuj(&S);
printf("Podaj dane:\n");
scanf("%c",&a);
a1=a-'0';
push(&S,a1);
scanf("%c",&b);
b1=b-'0';
push(&S,b1);





if((a == '+' || a == '*' || a == '/') && a != 'q' ){




    switch (a)
    {
    case '+':
        
        
        break;

    default:
        break;
    }


}
}