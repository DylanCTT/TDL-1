#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nombre_texto[100], nombre_binario[100], caracter;
    FILE *f_texto, *f_binario;
    int pos = 0, encontrados = 0;
    
    // Leer nombres de archivos y el carácter
    printf("Nombre del archivo de texto: ");
    scanf("%99s", nombre_texto);
    printf("Nombre del archivo binario: ");
    scanf("%99s", nombre_binario);
    printf("Carácter a buscar: ");
    scanf(" %c", &caracter); // Espacio para saltar posibles saltos de línea

    // Abrir archivos
    f_texto = fopen(nombre_texto, "r");
    if (!f_texto) {
        printf("No se pudo abrir el archivo de texto.\n");
        return 1;
    }
    f_binario = fopen(nombre_binario, "wb");
    if (!f_binario) {
        printf("No se pudo abrir el archivo binario.\n");
        fclose(f_texto);
        return 1;
    }

    // Recorrer archivo de texto y guardar posiciones
    int c;
    while ((c = fgetc(f_texto)) != EOF) {
        if ((char)c == caracter) {
            fwrite(&pos, sizeof(int), 1, f_binario);
            encontrados++;
        }
        pos++;
    }

    fclose(f_texto);
    fclose(f_binario);

    printf("Total de ocurrencias encontradas: %d\n", encontrados);
    printf("Las posiciones se guardaron en: %s\n", nombre_binario);
    return 0;
} 