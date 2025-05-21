#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*(a)
    int i=0;
    for (i=1;i<=50;i++){
        if (i%5==0)
            printf("%d es multiplio de 5 \n", i);
        else
            printf("%d no es multiplo \n", i);
    } */
    int i;
    for(i=5;i<=50;i+=5){
        printf("%d es multiplo de 5\n ", i);
    }

}
