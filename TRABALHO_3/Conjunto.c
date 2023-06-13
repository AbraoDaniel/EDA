#include "Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

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
        int temElemento = 0; // Variável para verificar se o conjunto possui algum elemento
        int j;
        for (j = 0; j <= n; j++) {
            if (buscaConjunto(u, j) == i) {
                temElemento = 1;
                break;
            }
        }
        if (temElemento) {
            for (j = 0; j <= n; j++) {
                if (buscaConjunto(u, j) == i) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
}
