#include <stdio.h>
#include "Conjunto.h"


// Função para mostrar todos os conjuntos


int main() {
    int i, j, n;
    
    // Leitura da matriz de adjacência
    printf("Digite o número de vértices do grafo: ");
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

    // Criação dos conjuntos iniciais
    for (i = 0; i < n; i++) {
        cria_conjunto(&u, i);
    }

    // União dos conjuntos baseado na matriz de adjacência
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (adjacencia[i][j] == 1) {
                uniao_conjunto(&u, i, j);
            }
        }
    }

   mostrarConjuntos(&u, n+1);

    return 0;
}