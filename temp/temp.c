#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a;
    scanf("%d",&a);
    if(a<20)
        printf("Nie jest zbyt cieplo! \n");
    else if(20<=a)
        printf("Jest bardzo ladna pogoda!\n");

    return 0;
}
