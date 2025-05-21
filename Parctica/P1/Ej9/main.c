#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, res;
    char op;
    printf("Escriba el primer numero a operar: ");
    scanf("%d", &num1);
    printf("Escriba el segundo numero a operar: ");
    scanf(" %d", &num2);
    printf("Escriba el operador: ");
    scanf(" %c", &op);
    switch (op){
        case '+': res=num1 +num2;
        break;
        case '-': res=num1-num2;
        break;
        case'x':res=num1*num2;
        break;
        case'/': res=num1/num2;
        break;
        default: printf("el operador ingresado es incorrecto ");
    }
    printf("\n el resultado es: %d", res);
    return 0;
}
