#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f= fopen("diccionario.txt", "r");
    char str[80];
    char act[80];
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    printf(" Ingrese la palabra que quiere buscar: ");
    scanf(" %s", str);
    fscan(f, "%s\n;", act);
    while (!feof(f) && strcmp(str, 'FIN')!=0){

    }


    return 0;
}
