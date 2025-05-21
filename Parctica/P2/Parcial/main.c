#include <stdio.h>
#include <stdlib.h>
#define CANT 100

struct estudiante{
    int legajo;
    char carrera[80];
    char nombre[50];
    float promedio;
};

typedef struct estudiante estudiante_t;

void cargar_estudiante (estudiante_t * e){
    printf("Ingrese estudiante\n");
    printf("\tLegajo: "); scanf("%d", &e->legajo); // &(*e).legajo;
    printf("\nCarrera: "); scanf("%s", e->carrera);
    printf("\tNombre: "); scanf("%s", e->nombre);
    printf("\tPromedio: "); scanf("%f", &e->promedio);
}

estudiante_t crear_estudiante (){
    estudiante_t  e;
    printf("Ingrese estudiante\n");
    printf("\tLegajo: "); scanf("%d", &e.legajo); // &e.legajo;
    printf("\nCarrera: "); scanf("%s", e.carrera);
    printf("\tNombre: "); scanf("%s", e.nombre);
    printf("\tPromedio: "); scanf("%f", &e.promedio);
    return e;
}

int cant_estudiantes(estudiante_t v[], int n, char carrera[]){
    int i, cant = 0;
    for(i=0;i<n;i++){
        if(!strcmp(v[i].carrera, carrera)){
            cant++;
        }
    }
    return cant;
}

int main()
{
    int i;
    estudiante_t v[CANT];
    for(i=0;i<CANT;i++){
        cargar_estudiante(&v[i]);
    }

    char carrera[]="Ingenieria en Computacion";

    printf("Alumnos de %s: %d", carrera, cant_estudiantes(v, CANT, carrera));
    return 0;
}
