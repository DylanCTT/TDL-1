#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    for(i=1;i<=10;i++){
        printf("la raiz cuadrada de %d es: %lf\n",i, sqrt(i));
        printf("el cuadrado de %d es: %lf\n", i, pow(i,2));
        printf ("el cubo de %d es: %lf\n", i, pow(i,3));
    }
}
