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
    int pos;
    float prom;
    float min=99999;
    float vec[dimF];
    srand(time(NULL));
    cargarVec(vec);
    mostrarVec(vec);
    recorrerVec(vec, &pos, &prom, &min);
    printf("El valor promedio es: %f\n", prom);
    printf("El valor minimo es: %f\n", min);
    printf("La posicion del valor maximo es: %d\n", pos);
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

void recorrerVec(float vec[],int *pos, float *prom, float *min){
    int i;
    float aux=0;
    float max=-1;
    for(i=0;i<dimF;i++){
        aux+=vec[i];
        if (*min>vec[i])
            *min=vec[i];

        if (max<vec[i]){
            *pos=i;
            max=vec[i];
        }
    }
    *prom= aux/dimF;

}
