#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont[10]={0};
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    chequeoCant(cont, num);
    mostrarVec(cont);
    return 0;
}

void chequeoCant (int cont [10], int num){
    while (num>0){
        cont[num%10]+=1;
        num=num/10;
    }
}

void mostrarVec (int vec[10]){
    int i;
    for (i=0;i<10;i++){
            printf("[%d]", vec[i]);
            printf("\n");
    }
}
