#include <stdio.h>
#include <stdlib.h>
#define FIN "XXX"

int main()
{
    char palabra [50];
    int contO=0;
    do {
        printf("Ingrese una palabra: ");
        scanf (" %s", palabra);
        if (palabra[strlen(palabra)-1]=='o')
            contO++;
    } while ((strcmp(palabra, FIN))!=0);
    printf("La cantidad de palabras que terminan en o es: %d", contO);
    return 0;
}
