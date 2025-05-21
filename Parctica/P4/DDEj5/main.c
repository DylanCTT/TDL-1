#include <stdio.h>
#include <stdlib.h>
#define mayusculas "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define minusculas "abcdefghijklmnopqrstuvwxyz"
void leerOracion (char * ptr);
void calculoMinusMayus(char * ptr);

int main()
{
    char * ptr;
    ptr= (char *) malloc(100*sizeof(char));
    leerOracion(ptr);
    calculoMinusMayus(ptr);
    return 0;
}

void leerOracion(char *ptr){
    int i, j;
    for(i=0;i<10;i++){
        printf("Ingrese una oracion: \n");
        for(j=0;j<10;j++){
            gets(ptr);
        }
    }
}

void calculoMinusMayus (char *ptr){
    int i,minus=0,mayus=0;
    for (i=0;i<100;i++){
        if (strchr(mayusculas, ptr[i])!= 0){
            mayus++;
        }
        if (strchr(minusculas, ptr[i])!= 0){
            minus++;
        }
    }
    printf("La cantidad de letras mayusculas es %d, y de minusculas es %d", mayus, minus);
}
