#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void multi(int mat[][3], int c);
void cargarMat(int mat[][3]);
void mostrarMat (int mat[][3]);
int main()
{
    int mat [3][3];
    int c=2;
    cargarMat(mat);
    mostrarMat(mat);
    multi(mat,c);
    printf("\n");
    mostrarMat(mat);
    return 0;
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

void multi(int mat[][3], int c){
    int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat[i][j]*=c;
        }
    }
}
