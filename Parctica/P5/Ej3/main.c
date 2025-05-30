#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    int max=-1;
    int act;
    f=fopen("precipitaciones.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    while (fscanf(f,"%d%*[-]", &act)==1){
        if (act>max){
            max=act;
        }
    }
    printf("El valor maximo de precipitaciones es: %d", max);
    return 0;
}
