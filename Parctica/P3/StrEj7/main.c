#include <stdio.h>
#include <string.h>

int esPalindromoIndices(const char cadena[]) {
    int inicio = 0;
    int fin = strlen(cadena) - 1;

    while (inicio < fin) {
        if (cadena[inicio] != cadena[fin]) {
            return 0;  // No es palíndroma
        }
        inicio++;
        fin--;
    }
    return 1;  // Es palíndroma
}

int main() {
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    if (esPalindromoIndices(palabra)) {
        printf("La palabra es palíndroma.\n");
    } else {
        printf("La palabra NO es palíndroma.\n");
    }

    return 0;
}
