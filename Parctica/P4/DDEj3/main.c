#include <stdio.h>
#include <stdlib.h>

void ingresarValores(int *ptr,int  dimf);
int calculoMax(int *ptr, int dimf);

int main()
{
    int * ptr;
    int dimf;
    printf("Ingrese un numero: ");
    scanf("%d", &dimf);
    ptr= (int *) malloc(dimf*sizeof(int));
    ingresarValores(ptr, dimf);
    printf("el numero maximo en el vector dinamico es: %d", calculoMax(ptr, dimf));
    free(ptr);
    return 0;
}

void ingresarValores(int *ptr,int  dimf){
    int i;
    for (i=0;i<dimf;i++){
        printf("Ingrese un valor al vector dinamico: \n");
        scanf("%d", (ptr+i));
    }
}

int calculoMax(int* ptr, int dimf){
    int max=-1, i;
    for(i=0;i<dimf; i++){
        if (*(ptr+i)>max)
            max= *(ptr+i);
    }
    return max;
}
