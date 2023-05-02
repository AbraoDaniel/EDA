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