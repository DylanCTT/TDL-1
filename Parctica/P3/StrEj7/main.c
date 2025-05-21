#include <stdio.h>
#include <string.h>

int esPalindromoIndices(const char cadena[]) {
    int inicio = 0;
    int fin = strlen(cadena) - 1;

    while (inicio < fin) {
        if (cadena[inicio] != cadena[fin]) {
            return 0;  // No es pal�ndroma
        }
        inicio++;
        fin--;
    }
    return 1;  // Es pal�ndroma
}

int main() {
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    if (esPalindromoIndices(palabra)) {
        printf("La palabra es pal�ndroma.\n");
    } else {
        printf("La palabra NO es pal�ndroma.\n");
    }

    return 0;
}
