#include <stdio.h>
#include <stdlib.h>


int esPrimo (int i);

int main()
{
    int n;
    printf("ingrese el numero a revisar:\n");
    scanf("%d", &n);
    if (esPrimo(n)==0){
        printf("%d no es primo\n", n);
    }
    else{
        printf("%d es primo", n);
    }
    return 0;
}

int esPrimo (int i){
    if (i<2){
        return 1;
    }
    for (int j=2;j<i;j++){
        if (i%j==0) return 0;
    }
    return 1;

}
