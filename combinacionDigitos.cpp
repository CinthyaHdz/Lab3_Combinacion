#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DIGITOS 9  

char mapa[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

bool esValido(char *digitos) {
    for (int i = 0; i < strlen(digitos); i++) {
        if (digitos[i] < '2' || digitos[i] > '9') {
            return false; 
        }
    }
    return true;
}

void generarCombinaciones(char *digitos, int indice, char *combinacion) {
    if (digitos[indice] == '\0') {
        printf("%s\n", combinacion);
        return;
    }

    int num = digitos[indice] - '0';
    for (int i = 0; mapa[num][i] != '\0'; i++) {
        combinacion[indice] = mapa[num][i];
        combinacion[indice + 1] = '\0';
        generarCombinaciones(digitos, indice + 1, combinacion);
    }
}

int main() {
    char digitos[MAX_DIGITOS + 1]; 
    char formato[10];

    snprintf(formato, sizeof(formato), "%%%ds", MAX_DIGITOS);
    
    printf("Ingrese hasta %d digitos (2-9): ", MAX_DIGITOS);
    scanf(formato, digitos);

    if (strlen(digitos) == 0) {
        printf("No hay combinaciones.\n");
        return 0;
    }

    if (!esValido(digitos)) {
        printf("Error: Solo se permiten los digitos del 2 al 9.\n");
        return 0;
    }

    char combinacion[MAX_DIGITOS + 1] = {0}; 
    generarCombinaciones(digitos, 0, combinacion);

    return 0;
}

