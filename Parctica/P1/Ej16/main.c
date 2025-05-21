#include <stdio.h>
#include <stdlib.h>

void minMax (int n,float *min,float *max);

int main()
{
    int num;
    float min,max;
    printf("ingresa un numero:\n");
    scanf("%d", &num);
    minMax(num, &min, &max);
    printf("el valor maximo fue %f\n", max);
    printf("el valor minimo fue %f\n", min);
}

void minMax(int n, float *min, float *max){
    float act;
    *min=9999999;
    *max=-1;
    for (int i=0;i<n;i++) {
        printf("ingrese un numero float: \n");
        scanf("%f",&act);
        if (act>*max){
            *max=act;
        }
        if (act<*min){
            *min=act;
        }
    }


}
