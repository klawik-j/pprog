#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define freqmin 8
#define freqmax 14
#define liczbamin -10
#define liczbamax 10
#define end 99

int main(int argc, char const *argv[])
{
    int liczba=0;
    int znakp=0;
    int znak=0;
    int c=0;
    int i=0;
    
    
    while(i<10)
    {
        scanf("%d",&liczba);
        if(liczba<= liczbamax && liczba>=liczbamin)
        {
            i++;

            if(liczba<0)                            //*sprawdzenie czy nastapilo przeciecie z zerem*// 
            znak=2;                                 
            else if(liczba>0)
            znak=3;
            else
            znak=0;


            if(znak+znakp==5)
            c=c+2;
            else if(znak+znakp==2 || znak+znakp==3)
            c++;

            znakp=znak;
        }
        else if(liczba==99)
        {
            i=20;
            printf("niewystarczajaca liczba danych\n");
        };    


    };

    c=(c-1)/2;
    printf("liczba przeciec to %d \n\n", c);







    return 0;
}