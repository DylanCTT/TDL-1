#include <stdio.h>
#include <stdlib.h>

/*
EJEMPLO DE USO:

Compilar:
    gcc EJ6.c -o SumaNros.exe

Ejecutar:
    SumaNros.exe 1.5 2.5 3.0 4.0

Salida esperada:
    Suma: 11.00
    Promedio: 2.75
*/

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: Debe ingresar al menos un número como argumento.\n");
        printf("Ejemplo de uso: SumaNros.exe 1.5 2.5 3.0\n");
        return 1;
    }

    float suma = 0.0f;
    for (int i = 1; i < argc; i++) {
        float valor;
        if (sscanf(argv[i], "%f", &valor) != 1) {
            printf("Error: Argumento '%s' no es un número válido.\n", argv[i]);
            return 2;
        }
        suma += valor;
    }
    float promedio = suma / (argc - 1);
    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f\n", promedio);
    return 0;
} 