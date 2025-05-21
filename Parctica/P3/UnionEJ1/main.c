#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int p1[2];
    int p2[2];
}rectangulo1;

typedef struct{
    int p[2];
    int ancho_alto[2];
}rectangulo2;

typedef struct{
    int info[4];
}rectangulo3;

typedef union{
    rectangulo1 r1;
    rectangulo2 r2;
    rectangulo3 r3;
}union_;

typedef union{
    double y;
    int x;

}prueba;

int main()
{

    union_ r1
    return 0;
}
