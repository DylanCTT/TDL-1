#include <stdio.h>
#include <stdlib.h>

void ingresarValores(float *ptr,int  dimf);
float calculoPromedio(float *ptr, int dimf);

int main()
{
    float * ptr;
    int dimf;
    printf("Ingrese un numero: ");
    scanf("%d", &dimf);
    ptr= (float *) malloc(dimf*sizeof(float));
    ingresarValores(ptr, dimf);
    printf("el promedio del vector dinamico es: %f", calculoPromedio(ptr, dimf));
    free(ptr);
    return 0;
}

void ingresarValores(float *ptr,int  dimf){
    int i;
    for (i=0;i<dimf;i++){
        printf("Ingrese un valor al vector dinamico: \n");
        scanf("%f", (ptr+i));
    }
}

float calculoPromedio(float* ptr, int dimf){
    float prom=0;
    int i;
    for(i=0;i<dimf; i++){
            prom=prom+ptr[i];
    }
    return prom/dimf;
}
