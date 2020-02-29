#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a;
    int i=1;
    
    while(a!=99){
        printf("Podaj %i. wartosc parametru: ",i);
        scanf("%d",&a);
        
        if (a>= -5 && a<=5)
            printf("Aktualna wartosc parametru: %d\n", a);
        else if (a==99)
        ;
        else
            printf("Bledna wartosc parametru!\n");
        
        i++ ;
    }
    
    return 0;   
}