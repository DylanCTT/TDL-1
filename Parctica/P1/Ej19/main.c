#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Informar (pun);

int main()
{
    int res,op,alumno,num1,num2;
    int puntaje=0;

    srand(time(NULL));
    for (int i=0;i<4;i++){
        num1=(rand() % (100));
        num2=(rand() % (100));
        op=num1 + num2;
        printf("cuanto es %d + %d: \n", num1, num2);
        scanf("%d", &res);
        if (res==op){
            puntaje++;
        }
    }
    Informar(puntaje);
    return 0;
}

void Informar (int pun){
    switch (pun){
    case 0:
        printf("Tu puntaje es una E");
    break;
    case 1:
        printf("Tu puntaje es una D");
    break;
    case 2:
        printf("Tu puntaje es una C");
    break;
    case 3:
        printf("Tu puntaje es una B");
    break;
    case 4:
        printf("Tu puntaje es una A");
    break;
    default: printf("error");
    }
}
