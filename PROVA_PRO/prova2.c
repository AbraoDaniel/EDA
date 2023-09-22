#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(int primeiro, int segundo, int terceiro) {
    if(primeiro < segundo && primeiro < terceiro) {
        return primeiro;
    } else if(segundo < primeiro && segundo < terceiro) {
        return segundo;
    } else if(terceiro < primeiro && terceiro < segundo) {
        return terceiro;
    }
}

int main() {
    char a[] ="exercício";
    char b[] ="exército";

    int m = strlen(a);
    int n = strlen(b);

    int matriz[m][n];

    for(int i = 0; i < n; i++) {
        matriz[i][0] = i;
    }

    for(int j = 0; j < n; j++) {
        matriz[0][j] = j;
    }

    int custo, resultado;

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(a[i] == b[j]) {
                custo = 0;
            } else {
                custo = 1;
            }
            matriz[i][j] = min(matriz[i-1][j] + 1, matriz[i-1][j-1] + custo, matriz[i][j-1] +1);
            resultado = matriz[i][j]/2;
        }
    }

    printf("Custo = %d\n", resultado);

}