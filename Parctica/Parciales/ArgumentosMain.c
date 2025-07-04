// =============================
// Ejemplos y Explicación de Argumentos del main en C
// =============================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
========================================
1. Sintaxis de main con argumentos
========================================
int main(int argc, char* argv[])
{
    // ...
}
- argc: cantidad de argumentos (incluye el nombre del programa)
- argv: vector de cadenas (cada argumento como string)

========================================
2. Ejemplo Básico: Mostrar argumentos
========================================
*/
int ejemplo_basico(int argc, char* argv[]) {
    printf("Cantidad de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}

/*
========================================
3. Ejemplo: Sumar números pasados como argumentos
========================================
*/
int ejemplo_suma(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 ...\n", argv[0]);
        return 1;
    }
    float suma = 0;
    for (int i = 1; i < argc; i++) {
        float valor = atof(argv[i]);
        suma += valor;
    }
    printf("Suma: %.2f\n", suma);
    return 0;
}

/*
========================================
4. Ejemplo: Leer nombre de archivo y mostrar contenido
========================================
*/
int ejemplo_archivo(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s archivo.txt\n", argv[0]);
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 2;
    }
    char linea[256];
    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
    }
    fclose(f);
    return 0;
}

/*
========================================
5. Ejemplo: Procesar flags y opciones
========================================
*/
int ejemplo_flags(int argc, char* argv[]) {
    int debug = 0;
    char* archivo = NULL;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            debug = 1;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            archivo = argv[++i];
        }
    }
    printf("Debug: %s\n", debug ? "SI" : "NO");
    if (archivo) {
        printf("Archivo: %s\n", archivo);
    } else {
        printf("No se especificó archivo\n");
    }
    return 0;
}

/*
========================================
6. Cómo compilar y ejecutar programas con argumentos
========================================

Compilar con GCC:
    gcc ArgumentosMain.c -o argumentos.exe

Ejecutar con argumentos:
    argumentos.exe hola mundo 123
    argumentos.exe -d -f archivo.txt
    argumentos.exe 1.5 2.5 3.0

Ejemplo de salida:
    argumentos.exe hola mundo
    Cantidad de argumentos: 3
    argv[0]: argumentos.exe
    argv[1]: hola
    argv[2]: mundo

========================================
7. Recomendaciones
========================================
- Siempre verificar argc antes de acceder a argv[i]
- Usar sscanf o atof/atoi para convertir strings a números
- argv[0] es siempre el nombre del programa
- Los argumentos siempre son strings (char*)
*/

// =============================
// Programa principal de demostración
// =============================
int main(int argc, char* argv[]) {
    printf("\n--- Ejemplo Básico ---\n");
    ejemplo_basico(argc, argv);

    printf("\n--- Ejemplo Suma ---\n");
    ejemplo_suma(argc, argv);

    printf("\n--- Ejemplo Flags ---\n");
    ejemplo_flags(argc, argv);

    // Para probar ejemplo_archivo, descomentar:
    // ejemplo_archivo(argc, argv);

    return 0;
} 