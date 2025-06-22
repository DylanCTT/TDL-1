#include <stdio.h>
#include <stdlib.h>
#define tamanio 25
void imprimir(int * v, int size){
 int i;
 for (i=0; i<size; i++){
 printf("v[%d]= %d", i, v[i]);
 }
}
int main(){
 int v[tamanio];
 imprimir(v, tamanio);
 return 0;
}
