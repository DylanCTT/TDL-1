// =============================
// Memoria Dinámica en C: malloc, calloc, realloc
// =============================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
========================================
1. malloc
========================================
- Reserva un bloque de memoria de tamaño especificado (en bytes).
- No inicializa la memoria (puede contener basura).
- Devuelve un puntero void* (hay que castear).

Sintaxis:
    void* ptr = malloc(tamanio_en_bytes);

Ejemplo:
*/
void ejemplo_malloc() {
    int n = 5;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Error al asignar memoria con malloc\n");
        return;
    }
    for (int i = 0; i < n; i++) arr[i] = i * 2;
    printf("[malloc] Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

/*
========================================
2. calloc
========================================
- Reserva memoria para un arreglo de elementos e inicializa todo a cero.
- Sintaxis: void* ptr = calloc(num_elementos, tamanio_elemento);

Ejemplo:
*/
void ejemplo_calloc() {
    int n = 5;
    int* arr = (int*)calloc(n, sizeof(int));
    if (!arr) {
        printf("Error al asignar memoria con calloc\n");
        return;
    }
    printf("[calloc] Array inicializado: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

/*
========================================
3. realloc
========================================
- Cambia el tamaño de un bloque de memoria previamente asignado con malloc/calloc/realloc.
- Sintaxis: void* ptr_nuevo = realloc(ptr, nuevo_tamanio_en_bytes);

Ejemplo:
*/
void ejemplo_realloc() {
    int n = 3;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Error al asignar memoria con malloc\n");
        return;
    }
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    printf("[realloc] Array original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    // Redimensionar a 6 elementos
    int* arr2 = (int*)realloc(arr, 6 * sizeof(int));
    if (!arr2) {
        printf("Error al redimensionar memoria con realloc\n");
        free(arr);
        return;
    }
    for (int i = n; i < 6; i++) arr2[i] = (i + 1) * 10;
    printf("[realloc] Array redimensionado: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr2[i]);
    printf("\n");
    free(arr2);
}

/*
========================================
4. Ejemplo con estructuras
========================================
*/
typedef struct {
    int id;
    char nombre[20];
} Persona;

void ejemplo_struct() {
    int n = 2;
    Persona* personas = (Persona*)malloc(n * sizeof(Persona));
    if (!personas) {
        printf("Error al asignar memoria para estructuras\n");
        return;
    }
    strcpy(personas[0].nombre, "Juan"); personas[0].id = 1;
    strcpy(personas[1].nombre, "Ana"); personas[1].id = 2;
    printf("[struct] Personas:");
    for (int i = 0; i < n; i++)
        printf(" %s(%d)", personas[i].nombre, personas[i].id);
    printf("\n");
    free(personas);
}

/*
========================================
5. Buenas prácticas
========================================
- Siempre verificar si malloc/calloc/realloc devolvieron NULL
- Liberar la memoria con free(ptr) cuando ya no se usa
- No usar memoria después de liberarla
- Inicializar punteros a NULL después de liberar
*/

int main() {
    printf("\n--- Ejemplo malloc ---\n");
    ejemplo_malloc();
    printf("\n--- Ejemplo calloc ---\n");
    ejemplo_calloc();
    printf("\n--- Ejemplo realloc ---\n");
    ejemplo_realloc();
    printf("\n--- Ejemplo con struct ---\n");
    ejemplo_struct();
    return 0;
} 