#include <stdio.h>
#include <stdlib.h>
#define FIN "ZZZ"
int main()
{
    char str[25];
    int sum=0;
    printf("Ingerse una palabra: \n");
    scanf("%s", str);
    while (strcmp(str,FIN)!=0){
        if (strlen(str)==5){
            sum++;
        }
        printf("Ingerse una palabra: \n");
        scanf("%s", str);
    }
    printf("la cantidad de palabras ingresadas con 5 letras es: %d\n", sum);
    return 0;
}
