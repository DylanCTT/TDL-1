#include <stdio.h>
#include <stdlib.h>
#define dimF 10
#include <time.h>

float promedio (float vec[]);
float min (float vec[]);
float posMax(float vec[]);
void cargarVec(float vec[]);
void mostrarVec (float vec[]);

int main()
{
    srand(time(NULL));
    float vec[dimF];
    cargarVec(vec);
    mostrarVec(vec);
    printf("el promedio de los valores del arreglo es: %f\n", promedio(vec));
    printf("el valor minimo en el arreglo es: %f\n", min(vec));
    printf("la posicion del valor maximo del arreglo es: %f\n", posMax(vec));

    return 0;
}

void cargarVec(float vec[]){
    int i;
    for (i=0;i<dimF;i++){
        vec[i]= ((float)rand())/RAND_MAX*(10-5)+5; //  random de 5 a 10
    }
}

void mostrarVec (float vec[]){
    int i;
    for (i=0;i<dimF;i++){
        printf("%f\n ", vec[i]);
    }
}

float promedio (float vec[]){
    int i;
    float aux=0;
    for (i=0;i<dimF;i++){
        aux+=vec[i];
    }
    return aux/dimF;
}

float min (float vec[]){
    int i;
    float min=999999;
    for (i=0;i<dimF;i++){
        if (min>vec[i]){
            min=vec[i];
        }
    }
    return min;
}

float posMax (float vec[]){
    int i;
    float max=0;
    int pos;
    for (i=0;i<dimF;i++){
        if (max<vec[i]){
            pos=i;
            max=vec[i];
        }
    }
    return pos;
}


