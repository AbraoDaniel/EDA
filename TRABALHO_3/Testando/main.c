#include <stdio.h>
#include "Conjunto.h"

int main() {
    int i, j, n;

    printf("Digite o número de vértices do grafo: "); // Lendo matriz
    scanf("%d", &n);
    
    int adjacencia[n][n];
    printf("Digite a matriz de adjacência do grafo:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjacencia[i][j]);
        }
    }
    printf("\n");
    
    Conjuntos u;
    inicializa_conjunto(&u);

    for (i = 0; i < n; i++) { // Cria primeiros conjuntos
        cria_conjunto(&u, i);
    }

    
    for (i = 0; i < n; i++) { // unindo conjuntos
        for (j = i + 1; j < n; j++) {
            if (adjacencia[i][j] == 1) {
                unindo_conjuntos(&u, i, j);
            }
        }
    }

    mostrar_conjuntos(&u, n+1);

    return 0;
}