#include <stdio.h>
#include <stdlib.h>

#define fin 10
#define pi 3.1415
#define AREA_CIRCULO(r) pi *(r*r)
int main()
{
    srand(time(NULL));
    int i;
    for (i=0;i<fin;i++){
        int radio =3 + rand() % 8;
        printf("el el area de un circulo de radio %d es %f\n", radio, AREA_CIRCULO(radio));
    }
    return 0;
}
