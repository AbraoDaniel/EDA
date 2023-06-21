#include <stdio.h>
#include "Conjunto.h"

#define MAX_VERTICES 100

void mostra_conjuntos(Conjuntos u) {
    Elemento *p = u.l.cabeca;
    int indice = 0;
    while (p != NULL) {
        Lista *conjunto = (Lista *)p->info;
        Elemento *q = conjunto->cabeca;
        printf("Conjunto %d: ", indice);
        while (q != NULL) {
            int *valor = (int *)q->info;
            printf("%d ", *valor);
            q = q->proximo;
        }
        printf("\n");
        p = p->proximo;
        indice++;
    }
}

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
    
    Conjuntos u;
    inicializa_conjunto(&u);

    // Criação dos conjuntos iniciais
    for (i = 1; i <= n; i++) {
        cria_conjunto(&u, i);
    }

    // União dos conjuntos baseado na matriz de adjacência
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (adjacencia[i][j] == 1) {
                uniao_conjunto(&u, i, j);
            }
        }
    }

    mostra_conjuntos(u);

    return 0;
}