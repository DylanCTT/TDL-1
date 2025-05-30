#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char c;
    int minus=0, mayus=0;
    f= fopen("MayusMinus.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    c=fgetc(f);
    while (!feof(f)){
        if ((c>='a') && (c<='z')){
            minus++;
        }
        else if ((c>='A') && (c<='Z')){
            mayus++;
        }
        c=fgetc(f);
    }
    fclose(f);
    printf("el numero de minusculas es: %d\n", minus);
    printf("el numero de mayusculas es: %d", mayus);
    return 0;
}
