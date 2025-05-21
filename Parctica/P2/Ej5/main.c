#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMat(int mat[][3]);
void mostrarMat (int mat[][3]);

int main()
{
    int A [3][3];
    int B[3][3];
    int C [3][3];
    cargarMat(A);
    srand(time(NULL));
    cargarMat(B);
    mostrarMat(A);
    printf("\n    + \n");
    mostrarMat(B);
    suma(A,B,C);
    printf("\n    = \n");
    mostrarMat(C);
    return 0;
}

void suma(int A [3][3], int B [3][3],int C [3][3]){
    int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void cargarMat(int mat[][3]){
    int i,j;

    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat[i][j]= rand()%50+1;
        }
    }
}
void mostrarMat (int mat[][3]){
    int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
}
