// =============================
// Ejemplos de Preprocesador en C
// =============================
#include <stdio.h>
#include <stdlib.h>

// 1. #define - Definición de constantes y macros
#define PI 3.14159
#define SALUDO "Hola Mundo"
#define CUADRADO(x) ((x)*(x))

// 2. #include - Inclusión de archivos de cabecera
#include <string.h> // Biblioteca estándar
// #include "mi_biblio.h" // Archivo propio (comentado)

// 3. #ifdef, #ifndef, #endif - Compilación condicional
#define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(msg) printf("DEBUG: %s\n", msg)
#else
    #define DEBUG_PRINT(msg)
#endif

// 4. #if, #elif, #else - Compilación condicional avanzada
#define VERSION 2

#if VERSION == 1
    #define MENSAJE_VERSION "Versión 1"
#elif VERSION == 2
    #define MENSAJE_VERSION "Versión 2"
#else
    #define MENSAJE_VERSION "Otra versión"
#endif

// 5. #undef - Eliminar una macro
#undef PI
#define PI 3.14 // Redefinir PI

// 6. #error - Forzar error de compilación
/*
#if VERSION < 1
    #error "La versión debe ser al menos 1"
#endif
*/

// 7. #pragma - Directivas específicas del compilador
#pragma message ("Compilando archivo PreProcesador.c")

// 8. #line - Cambiar número de línea y nombre de archivo
#line 100 "ArchivoVirtual.c"

// 9. Operador # (stringificación)
#define A_STRING(x) #x

// 10. Operador ## (concatenación de tokens)
#define CONCAT(a, b) a##b

// 11. Macros variádicas (__VA_ARGS__)
#define LOG(fmt, ...) printf(fmt, __VA_ARGS__)

// 12. Macros predefinidas
// __FILE__, __LINE__, __DATE__, __TIME__, __func__

int main() {
    // #define y macros
    printf("PI: %f\n", PI);
    printf("Saludo: %s\n", SALUDO);
    printf("Cuadrado de 5: %d\n", CUADRADO(5));

    // #ifdef y #endif
    DEBUG_PRINT("Esto es un mensaje de debug");

    // #if, #elif, #else
    printf("Mensaje de versión: %s\n", MENSAJE_VERSION);

    // #undef y redefinición
    printf("PI redefinido: %f\n", PI);

    // #pragma (ver mensaje al compilar)

    // #line (ver en errores o depuración)
    printf("Esta línea es la %d en el archivo %s\n", __LINE__, __FILE__);

    // Operador # (stringificación)
    printf("Stringificación: %s\n", A_STRING(Ejemplo de texto));

    // Operador ## (concatenación de tokens)
    int valorXY = 42;
    printf("Concatenación de tokens: %d\n", CONCAT(valor, XY));

    // Macros variádicas
    LOG("Suma: %d + %d = %d\n", 2, 3, 2+3);

    // Macros predefinidas
    printf("Archivo: %s, Línea: %d\n", __FILE__, __LINE__);
    printf("Fecha: %s, Hora: %s\n", __DATE__, __TIME__);
    printf("Función: %s\n", __func__);

    return 0;
} 