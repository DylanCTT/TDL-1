#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    float monto, tot=0;
    int cod;
    f=fopen("apuestas.txt", "r");

    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }

    fscanf(f, "%d|%f;", &cod, &monto);
    while (!feof(f)){
        tot+=monto;
        fscanf(f, "%d|%f;", &cod, &monto);
    }
    fclose(f);
    printf(" El valor total de la apuesta es: %f", tot);
    return 0;
}
