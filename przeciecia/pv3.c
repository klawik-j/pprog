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
    int a=0;
    int b;
    int c=0;
    int i=0;
    int lserji=0;


while(lserji<5)                                    //*okreslam ile ma byc wykonanych serji pomiarow czestotliowsci, jezeli chce zeby wykonywal sie w nieskonczonosc trzeba usunac fraze "lserji++" i zamiast tego mozna dac ze przy pojawianiu sie liczby 99 "lserji=5"*//
{    
lserji++;
i=0;
c=0;

    scanf("%d",&liczba);                             //*cykl pierwszej liczby nie jest zawarty w petli poniewaz nie wiem jaka wartosc ustawi sie po zdadeklarowaniu ragumetu "b"*//
    
    if(liczba==end)
    {
        i=20;
        lserji=5;
        printf("koniec strumienia danych\n");
    };
    
    if(liczba<0)                             
    b=-1;                                 
    else if(liczba>0)
    b=1;
    else
    b=0;

    i++;


    while(i<5)                                     //*okreslam liczbe pomiarow w serji
    {
        scanf("%d",&liczba);
        if(liczba<= liczbamax && liczba>=liczbamin)
        {
            i++;

            if(liczba<0)                            //*sprawdzenie czy nastapilo przeciecie z zerem*// 
            a=-1;                                 
            else if(liczba>0)
            a=1;
            else
            a=0;

            if(a*b<0)
            {
            c++;
            b=a;
            }
            
            if(b==0)                                //*jezeli w pierwsza liczba to "0" ta fraza powoduje ze algorytm dziala dalej*//
            b=a;
            
        }
        else if(liczba==end)
        {
            i=20;
            lserji=5;
            printf("koniec strumienia danych\n");
        };    


    };

    
    printf("liczba przeciec to %d\n\n", c);

    if(c<=freqmin || c>=freqmax)
    printf("czestotliwosc z poza przedzialu !!!!!!\n");

};






    return 0;
}