#ifndef IMGGRAY_H
#define IMGGRAY_H

// Definición del tipo de dato para la imagen en escala de grises
typedef struct {
    int filas;
    int columnas;
    unsigned char **pixels; // Matriz dinámica de píxeles (0-255)
} ImgGray;

// Prototipos de funciones públicas
ImgGray* crear_imggray(int filas, int columnas);
void destruir_imggray(ImgGray *img);

#endif // IMGGRAY_H 