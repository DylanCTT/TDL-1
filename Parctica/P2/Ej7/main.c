#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarTensor(float datos[][12][10]);
float contMes(float datos[][12][10]);
float Promedido(float datos[][12][10]);
void minLluvia(float datos[][12][10]);
int minPromedio(float datos[][12][10]);

int main()
{
    srand(time(NULL));
    float datos [30][12][10];
    cargarTensor(datos);
    mostrarMat(datos);
    minLluvia(datos);
    printf("el mes en el que en promedio llovio menos: %d \n", minPromedio(datos));


    return 0;
}

void cargarTensor (float datos [][12][10]){
    int i,j,k;
    for (i=0;i<10;i++){
        for(j=0;j<12;j++){
            for(k=0;k<30;k++){
                datos[k][j][i]= ((float)rand())/RAND_MAX*(100);
            }
        }
    }
}

void minLluvia(float datos[][12][10]){
    float min;
    int mes;
    float cont;
    int i,j,k;
     for (i=0;i<10;i++){
        min=99999;
        for(j=0;j<12;j++){
            cont=0;
            for(k=0;k<30;k++){
                cont+=datos[k][j][i];
            }
        if (cont<min){
            min=cont;
            mes= j;
        }
        }
    printf("en el anio %d el mes en donde menos llovio fue: %f \n ", i, min );
    }
}

int minPromedio (float datos[][12][10]){
    int min=9999;
    float cont, anio;
    int i,j,k;
    int num;
    for (i=0;i<10;i++){
        cont=0;
        for(j=0;j<12;j++){
            for(k=0;k<30;k++){
                cont+=datos[k][j][i];
            }
        }
        anio= cont/360;
        if (anio<min){
            min=anio;
            num=i;
        }
    }
    return num;
}
void mostrarMat (float datos[][12][10]){
    int i,j,k;
    for (i=0;i<10;i++){
        for(j=0;j<12;j++){
            for (k=0;k<30;k++){
            printf("[%.2f]", datos[k][j][i]);
            }
        printf("\n");
        }
    printf("\n");
    }
}
