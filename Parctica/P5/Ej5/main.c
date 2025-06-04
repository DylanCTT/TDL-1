#include <stdio.h>
#include <stdlib.h>

int buscar_palabra(char **diccionario, int n, const char *palabra);

int main()
{
    FILE *f;
    f= fopen("diccionario.txt", "r");
    char str[80];
    char act[80];
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    char **diccionario = NULL;
    int capacidad = 10, cantidad = 0;
    diccionario = malloc(capacidad * sizeof(char*));


    char buffer[80];
    while (fgets(buffer, 80, f)) {
        buffer[strcspn(buffer, "\r\n")] = 0; // Eliminar salto de línea
        if (cantidad == capacidad) {
            capacidad *= 2;
            diccionario = realloc(diccionario, capacidad * sizeof(char*));
        }
        diccionario[cantidad] = malloc(strlen(buffer) + 1);
        strcpy(diccionario[cantidad], buffer);
        cantidad++;
    }
    fclose(f);

    // Pedir palabras al usuario hasta que escriba "ZZZ"
    char palabra[80];
    while (1) {
        printf("Ingrese la palabra que quiere buscar (ZZZ para terminar): ");
        scanf("%s", palabra);
        if (strcmp(palabra, "ZZZ") == 0)
            break;

        if (buscar_palabra(diccionario, cantidad, palabra))
            printf("La palabra '%s' SÍ pertenece al diccionario.\n", palabra);
        else
            printf("La palabra '%s' NO pertenece al diccionario.\n", palabra);
    }

    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        free(diccionario[i]);
    }
    free(diccionario);

    return 0;
}

int buscar_palabra(char **diccionario, int n, const char *palabra) {
    for (int i = 0; i < n; i++) {
        if (strcmp(diccionario[i], palabra) == 0) {
            return 1; // Encontrada
        }
    }
    return 0; // No encontrada
}
