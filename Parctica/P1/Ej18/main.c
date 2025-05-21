#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    srand(time(NULL));
    for (int i=0;i<15;i++){
        num=rand();
        printf("numero pseudo aleatorio %d\n", num);
    }

}
