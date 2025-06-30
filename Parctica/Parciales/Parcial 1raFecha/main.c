#include <stdio.h>
#include "imggray.h"

int main() {
    int filas = 5, columnas = 10;
    ImgGray *img = crear_imggray(filas, columnas);
    if (!img) {
        printf("Error al crear la imagen\n");
        return 1;
    }
    // Ejemplo: poner el pixel (2,3) a 128
    img->pixels[2][3] = 128;
    printf("Pixel (2,3): %d\n", img->pixels[2][3]);
    destruir_imggray(img);
    return 0;
} 