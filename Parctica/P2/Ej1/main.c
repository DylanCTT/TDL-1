#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int Array [50];
    int i;
    int contP=0;
    int contImp=0;
    for (i=0;i<50;i++){
        Array[i]= rand();
        printf("%d - ", Array[i]);
        if ((i%2 ==0)&& (Array[i]%2 !=0)){
            contImp++;
        }
        else if((i%2 !=0)&& (Array[i]%2 ==0))
            contP++;
    }
    printf("la cantidad de numeros impares en posiciones pares es %d\n", contImp);
    printf("la cantidad de numeros pares en posiciones impares es %d\n", contP);
    return 0;
}
