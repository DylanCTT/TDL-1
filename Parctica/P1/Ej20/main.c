#include <stdio.h>
#include <stdlib.h>

int damePar();

int main()
{
    int n;
    printf("ingresa un numero: \n");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        printf("Valor %d: %d\n",i,damePar());
    }
    return 0;
}
int damePar(){
    static int n=-2;
    return n+=2;
}
