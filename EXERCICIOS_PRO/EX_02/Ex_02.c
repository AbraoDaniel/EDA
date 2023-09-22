#include <stdio.h>
#include <stdlib.h>

// Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
// elemento no índice i seja o produto de todos os números na matriz original, com
// exceção de i.
// ○ Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
// ○ Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]

int main() {
    int v[] = {1,2,3,4,5};
    int n = 5;
    int montante = 1;
    int r[n];

    for(int i = 0; i < n; i ++) {
        montante*=v[i];
    }

    printf("[");
    for(int j = 0; j < n; j++) {
        r[j] = montante/v[j];
        printf("%4d", r[j]);
    }
    printf("]");

    
}