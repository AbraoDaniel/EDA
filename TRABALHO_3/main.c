#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Definição do TAD União-Busca

// Definição da estrutura de conjunto
typedef struct {
    int representante;
    // Outros membros do conjunto, se necessário
} Conjunto;

// Definição da estrutura União-Busca
typedef struct {
    Conjunto conjuntos[MAX_VERTICES];
    // Outros campos, se necessário
} UniaoBusca;

// Função de inicialização da estrutura União-Busca
void inicializar(UniaoBusca *u, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        u->conjuntos[i].representante = i;
    }
}

// Função Cria_Conjunto
void criaConjunto(UniaoBusca *u, int x) {
    u->conjuntos[x].representante = x;
}

// Função Busca_Conjunto
int buscaConjunto(UniaoBusca *u, int x) {
    return u->conjuntos[x].representante;
}

// Função União
void uniao(UniaoBusca *u, int x, int y) {
    int repX = buscaConjunto(u, x);
    int repY = buscaConjunto(u, y);
    u->conjuntos[repY].representante = repX;
}

// Função para mostrar todos os conjuntos
void mostrarConjuntos(UniaoBusca *u, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("Conjunto %d: ", i);
        int j;
        for (j = 0; j <= n; j++) {
            if (buscaConjunto(u, j) == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Função para destruição de um conjunto
void destruirConjunto(UniaoBusca *u, int x) {
    // Implemente a lógica de destruição de um conjunto, se necessário
}

// Função para desalocação de toda a estrutura
void desalocarEstrutura(UniaoBusca *u) {
    // Implemente a lógica de desalocação da estrutura, se necessário
}

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
