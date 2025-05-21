#include <stdio.h>
#include <stdlib.h>
void f (int * p);
int main(){
    int * ptr = NULL;
    f(ptr);
    if (ptr == NULL)
        printf("ptr es NULL\n");
    else
        printf("ptr no es NULL\n");
    return 0;
}

void f (int * p) {
    p = (int *) malloc(10*sizeof(int));
}

//el codigo imprime que ptr es null ya que lo que hace es inicializar la variable en null y despues alocar memoria desde ahi
//lo que hace con el ptr ==null es fijarse en la primera posicion que ya fue inicializada
