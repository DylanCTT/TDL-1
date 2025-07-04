#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para demostrar diferencias
typedef struct {
    char nombre[30];
    int edad;
    float altura;
    double salario;
} persona;

// Función para mostrar información de archivo
void mostrar_info_archivo(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir %s\n", nombre_archivo);
        return;
    }
    
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    fclose(archivo);
    
    printf("Tamaño de %s: %ld bytes\n", nombre_archivo, tamano);
}

// Función para escribir en archivo de texto
void escribir_texto(const char* nombre_archivo, persona* personas, int cantidad) {
    FILE* archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir archivo de texto\n");
        return;
    }
    
    printf("\n=== Escribiendo en archivo de texto ===\n");
    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s,%d,%.2f,%.2lf\n", 
                personas[i].nombre, 
                personas[i].edad, 
                personas[i].altura, 
                personas[i].salario);
        
        printf("Escrito: %s,%d,%.2f,%.2lf\n", 
               personas[i].nombre, 
               personas[i].edad, 
               personas[i].altura, 
               personas[i].salario);
    }
    fclose(archivo);
}

// Función para escribir en archivo binario
void escribir_binario(const char* nombre_archivo, persona* personas, int cantidad) {
    FILE* archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir archivo binario\n");
        return;
    }
    
    printf("\n=== Escribiendo en archivo binario ===\n");
    size_t escritos = fwrite(personas, sizeof(persona), cantidad, archivo);
    printf("Registros escritos: %zu\n", escritos);
    printf("Tamaño de estructura: %zu bytes\n", sizeof(persona));
    printf("Tamaño total esperado: %zu bytes\n", sizeof(persona) * cantidad);
    
    fclose(archivo);
}

// Función para leer archivo de texto
void leer_texto(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir archivo de texto para lectura\n");
        return;
    }
    
    printf("\n=== Leyendo archivo de texto ===\n");
    persona p;
    int contador = 0;
    
    while (fscanf(archivo, "%[^,],%d,%f,%lf\n", 
                  p.nombre, &p.edad, &p.altura, &p.salario) == 4) {
        printf("Registro %d: %s, %d años, %.2f m, $%.2lf\n", 
               ++contador, p.nombre, p.edad, p.altura, p.salario);
    }
    
    fclose(archivo);
}

// Función para leer archivo binario
void leer_binario(const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir archivo binario para lectura\n");
        return;
    }
    
    printf("\n=== Leyendo archivo binario ===\n");
    persona p;
    int contador = 0;
    
    while (fread(&p, sizeof(persona), 1, archivo) == 1) {
        printf("Registro %d: %s, %d años, %.2f m, $%.2lf\n", 
               ++contador, p.nombre, p.edad, p.altura, p.salario);
    }
    
    fclose(archivo);
}

// Función para mostrar contenido hexadecimal
void mostrar_hex(const char* nombre_archivo, int es_binario) {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir archivo para análisis hexadecimal\n");
        return;
    }
    
    printf("\n=== Contenido hexadecimal de %s ===\n", nombre_archivo);
    printf("Primeros 64 bytes:\n");
    
    unsigned char buffer[64];
    size_t leidos = fread(buffer, 1, 64, archivo);
    
    for (size_t i = 0; i < leidos; i++) {
        printf("%02X ", buffer[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
    
    fclose(archivo);
}

// Función para buscar y modificar registro específico
void modificar_registro_binario(const char* nombre_archivo, int indice, float nueva_altura) {
    FILE* archivo = fopen(nombre_archivo, "r+b");
    if (archivo == NULL) {
        printf("Error al abrir archivo para modificación\n");
        return;
    }
    
    // Mover al registro específico
    fseek(archivo, indice * sizeof(persona), SEEK_SET);
    
    persona p;
    if (fread(&p, sizeof(persona), 1, archivo) == 1) {
        printf("Registro original: %s, altura: %.2f\n", p.nombre, p.altura);
        
        // Modificar altura
        p.altura = nueva_altura;
        
        // Volver al inicio del registro y escribir
        fseek(archivo, indice * sizeof(persona), SEEK_SET);
        fwrite(&p, sizeof(persona), 1, archivo);
        
        printf("Registro modificado: %s, nueva altura: %.2f\n", p.nombre, p.altura);
    }
    
    fclose(archivo);
}

int main() {
    printf("=== COMPARACIÓN: Archivos de Texto vs Binarios ===\n\n");
    
    // Datos de prueba
    persona personas[] = {
        {"Juan Pérez", 25, 1.75, 45000.50},
        {"María García", 30, 1.62, 52000.75},
        {"Carlos López", 28, 1.80, 48000.25}
    };
    int cantidad = 3;
    
    // Mostrar información de la estructura
    printf("Tamaño de estructura 'persona': %zu bytes\n", sizeof(persona));
    printf("Campos: nombre[30]=%zu, edad=%zu, altura=%zu, salario=%zu\n",
           sizeof(personas[0].nombre), sizeof(personas[0].edad),
           sizeof(personas[0].altura), sizeof(personas[0].salario));
    
    // Escribir en ambos formatos
    escribir_texto("personas.txt", personas, cantidad);
    escribir_binario("personas.bin", personas, cantidad);
    
    // Mostrar información de archivos
    mostrar_info_archivo("personas.txt");
    mostrar_info_archivo("personas.bin");
    
    // Leer ambos archivos
    leer_texto("personas.txt");
    leer_binario("personas.bin");
    
    // Mostrar contenido hexadecimal
    mostrar_hex("personas.txt", 0);
    mostrar_hex("personas.bin", 1);
    
    // Demostrar modificación directa en archivo binario
    printf("\n=== Modificación directa en archivo binario ===\n");
    modificar_registro_binario("personas.bin", 1, 1.70);
    
    // Leer archivo binario después de modificación
    printf("\n=== Archivo binario después de modificación ===\n");
    leer_binario("personas.bin");
    
    return 0;
} 