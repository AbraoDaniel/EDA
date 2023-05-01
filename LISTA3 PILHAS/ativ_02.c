/*
implemente uma função que receba duas pilhas p1 e p2, e passe todos os elementos de p2
para o topo de p1. Essa função deve obedecer ao protótipo:
*/

#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

Pilha p1, p2;
int tam;
void concatena( Pilha *p1, Pilha *p2 );

int main(){
    printf("Quantos elementos deseja colocar? ");
    scanf("%d", &tam);

    inicializa_pilha (&p1, tam);
    inicializa_pilha (&p2, tam * 2);
    
    concatena(&p1, &p2);
    
    printf("Pilha 2 concatenada: \n");
    mostra_pilha(p2);
    
    desaloca_pilha( &p1 );
    desaloca_pilha( &p2 );
    return 1;
}

void concatena( Pilha *p1, Pilha *p2 ){
    printf("ELementos pilha 1: \n");
    while(!pilha_cheia(*p1)){
        int aux;
        scanf("%d", &aux);
        empilha(p1, aux);
    }
    printf("Pilha 1: \n");
    mostra_pilha(*p1);

    printf("ELementos pilha 2: \n");
    for(int i = 0; i < tam; i++){
        int aux;
        scanf("%d", &aux);
        empilha(p2, aux);
    }
    printf("Pilha 2: \n");
    mostra_pilha(*p2);

    while(!pilha_cheia(*p2)){
        int aux2;
        desempilha(p1, &aux2);
        empilha(p2, aux2);
    }
}