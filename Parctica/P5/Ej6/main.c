#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float min;
    float max;
    float suma;
    float contador;
}Estadisticas;

int main()
{
    FILE *info, *reporte;
    info=fopen("vinos.csv", "r");
    reporte=fopen("reporte_vinos.txt", "w");

    if (info==NULL){
        printf ("\nError al abrir archivo vinos\n");
        return 1;
    }
    if(reporte==NULL){
        printf ("\nError al abrir archivo reporte_vinos\n");
        return 1;
    }

    char linea[300];
    Estadisticas stats[8];

    //inicializo las estadisticas

    for (int i = 0; i < 8; i++) {
        stats[i].min = 999999; // Inicialización con un valor alto
        stats[i].max = -1; // Inicialización con un valor bajo
        stats[i].suma = 0;
        stats[i].contador = 0;
    }

    // Leer la primera línea y la agrego cambiandole ; por tab
    int i;
    if (fgets(linea, sizeof(linea), info) != NULL) {
        // Reemplazar ';' con '\t'
        for (i = 0; linea[i] != '\0'; i++) {
            if (linea[i] == ';') {
                linea[i] = '\t';
            }
        }
        // Escribir la línea en reporte
        fprintf(reporte, "%s\n", linea);
        printf("Guarde encabezados\n");
    }

    //proceso los datos de .csv
    int j;
    float actual[8];
    char noMeImporta[20];
    fscanf(info, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%s", &actual[0],&actual[1],&actual[2],&actual[3],&actual[4],&actual[5],&actual[6],&actual[7], noMeImporta );
    while (!feof(info)){
        for (i = 0; i<8; i++) {
            printf("procesado\n");
            stats[j].contador++;
            stats[j].suma+=actual[i];
            if (actual[i]<=stats[j].min){
                stats[j].min=actual[i];
            }
            if (actual[i]>=stats[j].max){
                stats[j].max=actual[i];
            }
        }
     fscanf(info, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%s", &actual[0],&actual[1],&actual[2],&actual[3],&actual[4],&actual[5],&actual[6],&actual[7], noMeImporta );
    }

    printf("termine de procesar\n");
    //agrego al reporte
    float prom;
    fprintf(reporte, "%s\t", "Promedio");
    for (i=0;i<8;i++){
        prom= (stats[i].suma/stats[i].contador);
        fprintf(reporte, "%f\t", prom);
    }
    fprintf(reporte, "\n");
    fprintf(reporte, "%s\t", "Maximo");
    for (i=0;i<8;i++){
        fprintf(reporte, "%f\t", stats[i].max);
    }
    fprintf(reporte, "\n");
    fprintf(reporte, "%s\t", "Minimo");
    for (i=0;i<8;i++){
        fprintf(reporte, "%f\t", stats[i].min);
    }
    fclose(info);
    fclose(reporte);
    printf("termine el programa\n");






    return 0;
}
