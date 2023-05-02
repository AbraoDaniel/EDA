/*
Implemente mais uma biblioteca de Filas, desta vez usando duas pilhas. Faça o include
da biblioteca de pilhas e declare a struct da fila com duas pilhas (p1 e p2) somente. A
implementação das funções da fila deve ser feita utilizando-se apenas as funções de
manipulação de pilhas (empilha, desempilha, pilha_cheia, etc.). Portanto, não é permitido
acessar diretamente os elementos da struct Pilha.
*/

#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

Pilha p1, p2;

int main(){
    int tam;
    scanf("%d", &tam);

    inicializa_pilha(&p1, tam);
    inicializa_pilha(&p2, tam);

    while(!pilha_cheia(p1)){
        int aux;
        scanf("%d", &aux);
        empilha(&p1, aux);
    }
    printf("Pilha 1: ");
    mostra_pilha(p1);

    while(!pilha_vazia(p1)){
        int aux;
        desempilha(&p1, &aux);
        empilha(&p2, aux);
    }
    mostra_pilha(p2);

    while (!pilha_vazia(p2)){
        int aux;
        desempilha(&p2, &aux);
        empilha(&p1, aux);
        printf("%d \n", aux);
    }
    

    return 1;
}