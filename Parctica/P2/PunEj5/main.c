#include <stdio.h>
#include <stdlib.h>
#define dimf 5

void invertirConPun(int vec[]);
void mostrarVec(int vec[]);
void swap (int *a, int *b);
int main()
{
    int vec[dimf]={0,1,2,3,4};
    mostrarVec(vec);
    invertirConPun(vec);
    mostrarVec(vec);
    return 0;
}

void invertirConPun(int vec[]){
    int *i,*j;
    i=vec;
    //i=&vec[0];
    j=vec+(dimf-1);
    //j=&vec[dimf-1];
    while (i<j){
        swap(i, j);
        i++;
        j--;
    }
}

void mostrarVec(int vec[]){
    int i;
    for (i=0;i<dimf;i++){
        printf("[%d]", vec[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a; // guarda el valor de a
    *a = *b; // almacena b en a
    *b = tmp; // almacena a en b
}
