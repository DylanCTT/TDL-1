#include "imggray.h"
#include <stdlib.h>

ImgGray* crear_imggray(int filas, int columnas) {
    ImgGray *img = (ImgGray*)malloc(sizeof(ImgGray));
    if (!img) return NULL;
    img->filas = filas;
    img->columnas = columnas;
    img->pixels = (unsigned char**)malloc(filas * sizeof(unsigned char*));
    if (!img->pixels) {
        free(img);
        return NULL;
    }
    for (int i = 0; i < filas; ++i) {
        img->pixels[i] = (unsigned char*)calloc(columnas, sizeof(unsigned char));
        if (!img->pixels[i]) {
            // Liberar lo que ya se reservó
            for (int j = 0; j < i; ++j) free(img->pixels[j]);
            free(img->pixels);
            free(img);
            return NULL;
        }
    }
    return img;
}

void destruir_imggray(ImgGray *img) {
    if (!img) return;
    for (int i = 0; i < img->filas; ++i) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
} 