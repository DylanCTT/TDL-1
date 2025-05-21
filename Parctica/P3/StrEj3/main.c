#include <stdio.h>
#include <stdlib.h>

void intercambio (char *cadena, char a, char b);

int main()
{
    char cadena [50];
    char a;
    char b;
    printf("Ingrese una palabra: ");
    scanf(" %s", cadena);
    printf("Ingrese una letra en esa palabra: ");
    scanf(" %c", &a);
    printf("Ingrese una letra en esa palabra: ");
    scanf(" %c", &b);
    printf("la palabra que ingresaste es: %s\n", cadena);
    intercambio(&cadena, a,b);
    printf("la palabra con las letras intercambiadas es: %s", cadena);
    return 0;

}

void intercambio (char *cadena, char a, char b){
    int i;
    for(i=0;i<=strlen(cadena); i++){
        if (cadena[i]==a)
            cadena[i]=b;
    }
}
