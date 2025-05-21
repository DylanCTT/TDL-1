#include <stdio.h>
#include <stdlib.h>
typedef struct {
        char calle[50];
        char ciudad[30];
        int cp;
        char pais[40];
    }dir ;

    typedef struct  {
        char apellido[50];
        char nombre[50];
        char legajo[8];
        float promedio;
        dir domicilio;
    }alumno[50];

void inicializarAlu (alumno *a);
void imprimir_alumno(const alumno a);

int main()
{
    alumno a;
    inicializarAlu(&a);
    imprimir_alumno(a);
    return 0;
}

void inicializarAlu (alumno *a){
    printf("ingrese el nombre del alumno\n");
    scanf("%s", a->nombre);
    printf("ingrese el apellido del alumno\n");
    scanf("%s", a->apellido);
    printf("ingrese el legajo del alumno\n");
    scanf("%s", a->legajo);
    printf("ingrese el promedio del alumno\n");
    scanf("%f", &a->promedio);
    printf("ingrese la calle donde vive el alumno\n");
    scanf("%s", a->domicilio.calle);
    printf("ingrese la ciudad donde vive el alumno\n");
    scanf("%s", a->domicilio.ciudad);
    printf("ingrese el pais del alumno\n");
    scanf("%s", a->domicilio.pais);
    printf("ingrese el codigo postal del alumno\n");
    scanf("%d", &a->domicilio.cp);
}
void imprimir_alumno(const alumno a){
    printf("Calle:%s\n ",a.domicilio.calle);
    printf("Ciudad:%s\n ",a.domicilio.ciudad);
    printf("Codigo postal:%d\n ",a.domicilio.cp);
    printf("Pais:%s\n ",a.domicilio.pais);
    printf("Apellido:%s\n ",a.apellido);
    printf("Nombre:%s\n ",a.nombre);
    printf("Legajo:%s\n ",a.legajo);
    printf("Promedio:%f\n ",a.promedio);


}
