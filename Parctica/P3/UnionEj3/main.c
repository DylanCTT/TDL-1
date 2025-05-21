#include <stdio.h>
#include <stdlib.h>
typedef union{
    int DNI;
    char pasaporte[50];
}iden;

typedef struct estudiante{
    char apellido[100];
    char nombre[100];
    int legajo;
    iden identificacion;
}est;





int main()
{
    est e;
    char nacionalidad[50];
    printf("Ingrese el apellido del estudiante:\n ");
    scanf(" %s", e.apellido);
    printf("Ingrese el nombre del estudiante:\n ");
    scanf(" %s", e.nombre);
    printf("Ingrese el legajo del estudiante:\n ");
    scanf(" %d", &e.legajo);
    printf("Ingrese si el estudiante es extranjero o es argentino:\n ");
    scanf(" %s", nacionalidad);
    if (strcmp(nacionalidad, "extranjero")==0){
        printf("Ingrese el pasaporte del estudiante:\n ");
        scanf(" %s", e.identificacion.pasaporte);
         printf("el estudiante es %s %s, su numero de legajo es %d, y su identificacion es %s", e.apellido, e.nombre, e.legajo, e.identificacion.pasaporte);
    }
    else{
        printf("Ingrese el DNI del estudiante:\n ");
        scanf(" %d", &e.identificacion.DNI);
         printf("el estudiante es %s %s, su numero de legajo es %d, y su identificacion es %d", e.apellido, e.nombre, e.legajo, e.identificacion.DNI);
    }


    return 0;
}
