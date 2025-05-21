#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int dia: 5;
    unsigned int mes: 4;
    unsigned int anio: 16;
}_fecha;


typedef union{
    _fecha f;
    unsigned int cmp;
}fecha;


int main()
{
    fecha f1;
    f1.f.dia=31;
    f1.f.mes=1;
    f1.f.anio=2005;

    fecha f2;
    f2.f.dia=23;
    f2.f.mes=5;
    f2.f.anio=2005;
    if(f1.cmp<=f2.cmp) printf("funciono");
    return 0;
}
