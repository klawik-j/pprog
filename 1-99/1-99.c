#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[])
{
    for (int i=1;i<100;i++)
    {
        printf("%2d ", i);
        if(i%10==0)
            printf("\n");
    }
    return 0;
}
