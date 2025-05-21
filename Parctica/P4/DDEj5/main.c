#include <stdio.h>
#include <stdlib.h>


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
        if (ptr[i]>= 'A')&&(ptr[i]<='Z'){
            mayus++;
        }
        if (ptr[i]>= 'a')&&(ptr[i]<='z'){
            minus++;
        }
    }
    printf("La cantidad de letras mayusculas es %d, y de minusculas es %d", mayus, minus);
}
