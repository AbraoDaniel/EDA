#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"
#include "Conjunto.c"

// Função principal
int main() {
    int i, j, n;
    // Leitura da matriz de adjacência
    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &n);
   
    int adjacencia[MAX_VERTICES + 1][MAX_VERTICES + 1];
    printf("Digite a matriz de adjacência do grafo:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adjacencia[i][j]);
        }
    }
    printf("\n");

    UniaoBusca u;
    inicializar(&u, n);

    // Criação dos conjuntos individuais para cada vértice
    for (i = 1; i <= n; i++) {
        criaConjunto(&u, i);
    }

    // União dos conjuntos com base nas arestas do grafo
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (adjacencia[i][j] && buscaConjunto(&u, i) != buscaConjunto(&u, j)) {
                uniao(&u, i, j);
            }
        }
    }

    // Mostrar os conjuntos encontrados
    mostrarConjuntos(&u, n);

    return 0;
}
