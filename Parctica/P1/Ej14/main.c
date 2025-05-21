#include <stdio.h>
#include <stdlib.h>

int espejo (int n);

int main()
{
    int num;
    printf("ingrese el numero a invertir:\n");
    scanf("%d", &num);
    printf("el numero ingresado fue: %d\n", num);
    printf("el numero en espejo es: %d", espejo(num));
}

int espejo (int n){
    int aux;
    int resultado;
    while (!(n==0)){
        aux=n%10;
        n=n/10;
        resultado=(resultado *10)+aux;
    }
    return resultado;
}
