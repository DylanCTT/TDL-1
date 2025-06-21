#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc !=5){
        printf("El programa no tiene los argumentos suficientes");
        return 1;
    }
    else {
        double suma=0;
        int i;
        for(i=1;i<=4;i++){
            suma+=atof(argv[i]);
        }
        double promedio = suma/4;
        printf("El promedio es: %f", promedio);
    }
    return 0;
}
