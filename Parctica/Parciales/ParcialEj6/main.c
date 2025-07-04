#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura producto según el enunciado
typedef struct {
    char codigo[20];
    int stock;
} producto;

/*
 * Función que procesa un archivo binario y escribe su contenido en un archivo de texto
 * Parámetros:
 * - nombreBinario: nombre del archivo binario de entrada
 * - nombreTexto: nombre del archivo de texto de salida
 * Retorna:
 * - 1: éxito
 * - 2: problemas con archivo de texto
 * - 3: problemas con archivo binario
 */
int procesarArchivos(const char* nombreBinario, const char* nombreTexto) {
    FILE *archivoBinario, *archivoTexto;
    producto prod;
    
    // Abrir archivo binario para lectura
    archivoBinario = fopen(nombreBinario, "rb");
    if (archivoBinario == NULL) {
        return 3; // Problemas con archivo binario
    }
    
    // Abrir archivo de texto para escritura
    archivoTexto = fopen(nombreTexto, "w");
    if (archivoTexto == NULL) {
        fclose(archivoBinario);
        return 2; // Problemas con archivo de texto
    }
    
    // Leer productos del archivo binario y escribir en el archivo de texto
    while (fread(&prod, sizeof(producto), 1, archivoBinario) == 1) {
        // Escribir código y stock separados por ;
        fprintf(archivoTexto, "%s;%d\n", prod.codigo, prod.stock);
    }
    
    // Cerrar archivos
    fclose(archivoBinario);
    fclose(archivoTexto);
    
    return 1; // Éxito
}

// Función auxiliar para crear un archivo binario de prueba
void crearArchivoBinarioPrueba(const char* nombreArchivo) {
    FILE *archivo;
    producto productos[] = {
        {"PROD001", 50},
        {"PROD002", 25},
        {"PROD003", 100},
        {"ABC123", 75},
        {"XYZ789", 30}
    };
    int numProductos = sizeof(productos) / sizeof(producto);
    
    archivo = fopen(nombreArchivo, "wb");
    if (archivo != NULL) {
        fwrite(productos, sizeof(producto), numProductos, archivo);
        fclose(archivo);
        printf("Archivo binario de prueba creado: %s\n", nombreArchivo);
    } else {
        printf("Error al crear archivo binario de prueba\n");
    }
}

int main() {
    const char* archivoBinario = "productos.bin";
    const char* archivoTexto = "productos.txt";
    int resultado;
    
    printf("=== Procesamiento de Archivos Binarios a Texto ===\n\n");
    
    // Crear archivo binario de prueba
    crearArchivoBinarioPrueba(archivoBinario);
    
    // Procesar archivos
    resultado = procesarArchivos(archivoBinario, archivoTexto);
    
    // Mostrar resultado
    switch (resultado) {
        case 1:
            printf("Procesamiento exitoso!\n");
            printf("Los datos se han guardado en: %s\n", archivoTexto);
            break;
        case 2:
            printf("Error: Problemas con el archivo de texto\n");
            break;
        case 3:
            printf("Error: Problemas con el archivo binario\n");
            break;
        default:
            printf("Error desconocido\n");
    }
    
    return 0;
}
