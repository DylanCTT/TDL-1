#include <stdio.h>
#include <stdlib.h>

int factorialRecursivo (int n);
//int factorialIterativo(int n);

int main()
{
    int num;
    printf("ingrese un numero: \n");
    scanf("%d",&num);
    printf("el factorial de %d es: %d", num, factorialRecursivo(num));
    return 0;
}
/*int factorialIterativo(int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res=res*i;
    }
    return res;
}*/

int factorialRecursivo (int n){
    int res;
    if (n==1)
        return 1;
    else{
        res=n*factorialRecursivo(n-1);
    }
    return res;
}

