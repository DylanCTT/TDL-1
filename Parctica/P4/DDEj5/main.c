#include <stdio.h>
#include <stdlib.h>


void leerOracion (char * ptr);
void calculoMinusMayus(char * ptr);

int main()
{
    int i, cant =10;
    char * ptr;
    ptr= (char *) malloc(100*sizeof(char));
    for(i=0;i<cant;i++){
        gets(ptr);
        calculoMinusMayus(ptr);
    }
    return 0;
}


void calculoMinusMayus (char *ptr){
    int i=0 ,minus=0,mayus=0;
    while (ptr[i]!='\0'){
        if ((ptr[i]>= 'A')&&(ptr[i]<='Z')){
            mayus++;
        }
        if ((ptr[i]>= 'a')&&(ptr[i]<='z')){
            minus++;
        }
        i++;
    }
    printf("La cantidad de letras mayusculas en la oracion es %d, y de minusculas en la oracion es %d", mayus, minus);
}
