#include <stdio.h>
#include <stdlib.h>

int main()
{
    float km, millas;
    printf(" Ingrese la distancia en kilometros: \n");
    scanf("%f", &km);
    millas= km/1.61;
    printf("la distancia en millas es: %f", millas);
    return 0;
}
