#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ejemplo 1: Estructura simple
typedef struct {
    int id;
    char nombre[20];
    float precio;
} producto;

// Ejemplo 2: Estructura con arrays
typedef struct {
    char codigo[10];
    int stock[5];  // Stock por mes
    double ventas_totales;
} inventario;

// Ejemplo 3: Estructura con punteros (cuidado con archivos binarios)
typedef struct {
    char* nombre_dinamico;  // ⚠️ PELIGROSO en archivos binarios
    int edad;
} persona_dinamica;

// Función para demostrar ventajas de archivos binarios
void demo_ventajas_binarios() {
    printf("=== VENTAJAS DE ARCHIVOS BINARIOS ===\n\n");
    
    // 1. Tamaño predecible
    producto productos[] = {
        {1, "Laptop", 999.99},
        {2, "Mouse", 25.50},
        {3, "Teclado", 89.99}
    };
    
    printf("1. TAMAÑO PREDECIBLE:\n");
    printf("   - Tamaño de estructura: %zu bytes\n", sizeof(producto));
    printf("   - Tamaño total: %zu bytes\n", sizeof(productos));
    printf("   - Número de registros: %zu\n\n", sizeof(productos) / sizeof(producto));
    
    // 2. Acceso directo a registros
    FILE* archivo = fopen("productos.bin", "wb");
    fwrite(productos, sizeof(producto), 3, archivo);
    fclose(archivo);
    
    printf("2. ACCESO DIRECTO A REGISTROS:\n");
    archivo = fopen("productos.bin", "rb");
    
    // Leer registro específico (índice 1)
    producto prod;
    fseek(archivo, 1 * sizeof(producto), SEEK_SET);
    fread(&prod, sizeof(producto), 1, archivo);
    printf("   - Registro 1: %s, $%.2f\n", prod.nombre, prod.precio);
    
    // Leer registro específico (índice 2)
    fseek(archivo, 2 * sizeof(producto), SEEK_SET);
    fread(&prod, sizeof(producto), 1, archivo);
    printf("   - Registro 2: %s, $%.2f\n", prod.nombre, prod.precio);
    
    fclose(archivo);
}

// Función para demostrar desventajas de archivos binarios
void demo_desventajas_binarios() {
    printf("\n=== DESVENTAJAS DE ARCHIVOS BINARIOS ===\n\n");
    
    // 1. Problemas de portabilidad
    printf("1. PROBLEMAS DE PORTABILIDAD:\n");
    printf("   - Endianness (little-endian vs big-endian)\n");
    printf("   - Tamaño de tipos de datos\n");
    printf("   - Alineación de estructuras\n\n");
    
    // 2. No legible por humanos
    printf("2. NO LEGIBLE POR HUMANOS:\n");
    printf("   - Contenido en bytes puros\n");
    printf("   - Requiere herramientas especiales para ver\n\n");
    
    // 3. Problemas con punteros
    printf("3. PROBLEMAS CON PUNTEROS:\n");
    printf("   - Los punteros no son portables\n");
    printf("   - Direcciones de memoria específicas del sistema\n\n");
}

// Función para mostrar diferencias de rendimiento
void demo_rendimiento() {
    printf("=== COMPARACIÓN DE RENDIMIENTO ===\n\n");
    
    // Crear datos de prueba
    inventario inv[1000];
    for (int i = 0; i < 1000; i++) {
        sprintf(inv[i].codigo, "PROD%04d", i);
        for (int j = 0; j < 5; j++) {
            inv[i].stock[j] = rand() % 100;
        }
        inv[i].ventas_totales = rand() % 10000;
    }
    
    // Medir tiempo de escritura binaria
    clock_t inicio = clock();
    FILE* archivo_bin = fopen("inventario.bin", "wb");
    fwrite(inv, sizeof(inventario), 1000, archivo_bin);
    fclose(archivo_bin);
    clock_t fin = clock();
    double tiempo_bin = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    
    // Medir tiempo de escritura texto
    inicio = clock();
    FILE* archivo_txt = fopen("inventario.txt", "w");
    for (int i = 0; i < 1000; i++) {
        fprintf(archivo_txt, "%s,%d,%d,%d,%d,%d,%.2f\n",
                inv[i].codigo,
                inv[i].stock[0], inv[i].stock[1], inv[i].stock[2],
                inv[i].stock[3], inv[i].stock[4],
                inv[i].ventas_totales);
    }
    fclose(archivo_txt);
    fin = clock();
    double tiempo_txt = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tiempo de escritura:\n");
    printf("   - Binario: %.6f segundos\n", tiempo_bin);
    printf("   - Texto:   %.6f segundos\n", tiempo_txt);
    printf("   - Diferencia: %.2fx más rápido el binario\n\n", tiempo_txt / tiempo_bin);
}

// Función para mostrar casos de uso específicos
void casos_uso_especificos() {
    printf("=== CASOS DE USO ESPECÍFICOS ===\n\n");
    
    printf("1. CUÁNDO USAR ARCHIVOS BINARIOS:\n");
    printf("   ✓ Grandes volúmenes de datos\n");
    printf("   ✓ Acceso aleatorio frecuente\n");
    printf("   ✓ Aplicaciones de alto rendimiento\n");
    printf("   ✓ Datos que no necesitan ser legibles\n");
    printf("   ✓ Estructuras de datos complejas\n\n");
    
    printf("2. CUÁNDO USAR ARCHIVOS DE TEXTO:\n");
    printf("   ✓ Datos que deben ser legibles\n");
    printf("   ✓ Intercambio entre sistemas\n");
    printf("   ✓ Configuraciones y logs\n");
    printf("   ✓ Datos que se editan manualmente\n");
    printf("   ✓ Portabilidad entre plataformas\n\n");
}

// Función para mostrar técnicas avanzadas
void tecnicas_avanzadas() {
    printf("=== TÉCNICAS AVANZADAS ===\n\n");
    
    // 1. Archivos con índices
    printf("1. ARCHIVOS CON ÍNDICES:\n");
    typedef struct {
        int id;
        long posicion;  // Posición en el archivo de datos
    } indice;
    
    // Crear archivo de datos
    producto datos[] = {
        {101, "Producto A", 100.0},
        {102, "Producto B", 200.0},
        {103, "Producto C", 300.0}
    };
    
    FILE* datos_file = fopen("datos.bin", "wb");
    fwrite(datos, sizeof(producto), 3, datos_file);
    fclose(datos_file);
    
    // Crear archivo de índices
    indice indices[] = {
        {101, 0 * sizeof(producto)},
        {102, 1 * sizeof(producto)},
        {103, 2 * sizeof(producto)}
    };
    
    FILE* indice_file = fopen("indices.bin", "wb");
    fwrite(indices, sizeof(indice), 3, indice_file);
    fclose(indice_file);
    
    printf("   - Archivo de datos: datos.bin\n");
    printf("   - Archivo de índices: indices.bin\n");
    printf("   - Permite búsqueda rápida por ID\n\n");
    
    // 2. Archivos con encabezado
    printf("2. ARCHIVOS CON ENCABEZADO:\n");
    typedef struct {
        char magic[4];      // "PROD"
        int version;        // 1
        int num_registros;  // Número de registros
        long timestamp;     // Fecha de creación
    } encabezado;
    
    encabezado header = {"PROD", 1, 3, time(NULL)};
    
    FILE* archivo_con_header = fopen("con_header.bin", "wb");
    fwrite(&header, sizeof(encabezado), 1, archivo_con_header);
    fwrite(datos, sizeof(producto), 3, archivo_con_header);
    fclose(archivo_con_header);
    
    printf("   - Magic number: %s\n", header.magic);
    printf("   - Versión: %d\n", header.version);
    printf("   - Registros: %d\n", header.num_registros);
    printf("   - Timestamp: %ld\n\n", header.timestamp);
}

// Función para mostrar manejo de errores
void manejo_errores_archivos() {
    printf("=== MANEJO DE ERRORES ===\n\n");
    
    printf("1. VERIFICACIÓN DE APERTURA:\n");
    FILE* archivo = fopen("archivo_inexistente.bin", "rb");
    if (archivo == NULL) {
        perror("Error al abrir archivo");
        printf("   - Archivo no existe o no se puede abrir\n");
    } else {
        fclose(archivo);
    }
    
    printf("\n2. VERIFICACIÓN DE LECTURA/ESCRITURA:\n");
    archivo = fopen("test.bin", "wb");
    if (archivo != NULL) {
        producto p = {1, "Test", 99.99};
        size_t escritos = fwrite(&p, sizeof(producto), 1, archivo);
        if (escritos != 1) {
            printf("   - Error: No se escribió el registro completo\n");
        } else {
            printf("   - Registro escrito correctamente\n");
        }
        fclose(archivo);
    }
    
    printf("\n3. VERIFICACIÓN DE POSICIONAMIENTO:\n");
    archivo = fopen("test.bin", "rb");
    if (archivo != NULL) {
        if (fseek(archivo, 1000, SEEK_SET) != 0) {
            printf("   - Error: No se pudo posicionar en el archivo\n");
        } else {
            printf("   - Posicionamiento exitoso\n");
        }
        fclose(archivo);
    }
}

int main() {
    printf("=== EJEMPLOS AVANZADOS DE ARCHIVOS BINARIOS ===\n\n");
    
    demo_ventajas_binarios();
    demo_desventajas_binarios();
    demo_rendimiento();
    casos_uso_especificos();
    tecnicas_avanzadas();
    manejo_errores_archivos();
    
    printf("=== FIN DE EJEMPLOS ===\n");
    return 0;
} 