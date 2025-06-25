#ifndef DICCIONARIO_H_INCLUDED
#define diccionario.c
#endif // diccionario

#include <stdio.h>
#include <stdlib.h>
#define MAX_PALABRA 50


void crearDiccionario();

int palabraExiste(const char *nombreArchivo, const char *palabra) ;

void agregarPalabra(const char *nombreArchivo, const char *palabra) {
    if (!palabraExiste(nombreArchivo, palabra)) {
        FILE *archivo = fopen(nombreArchivo, "a");
        if (archivo) {
            fprintf(archivo, "%s\n", palabra);
            fclose(archivo);
            printf("Palabra '%s' agregada.\n", palabra);
        }
    } else {
        printf("La palabra '%s' ya está en el diccionario.\n", palabra);
    }
}

int eliminarPalabra(const char *nombreArchivo, const char *palabraObjetivo) {
    FILE *original = fopen(nombreArchivo, "r");
    FILE *temporal = fopen("temp.txt", "w");
    int eliminada = 0;

    if (!original || !temporal) {
        printf("Error al abrir archivos.\n");
        return 0;
    }

    char palabra[MAX_PALABRA];
    while (fgets(palabra, sizeof(palabra), original)) {
        palabra[strcspn(palabra, "\n")] = 0;

        if (strcmp(palabra, palabraObjetivo) == 0) {
            eliminada = 1;
        } else {
            fprintf(temporal, "%s\n", palabra);
        }
    }

    fclose(original);
    fclose(temporal);

    remove(nombreArchivo);
    rename("temp.txt", nombreArchivo);

    return eliminada;
}

#endif







