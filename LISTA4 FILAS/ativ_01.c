/*
gcc ./estatica/Fila.c Pilha.c ativ_01.c  && ./a.out 

Escreva um programa que insere alguns valores em uma fila. Em seguida, ele deve
inverter a ordem de seus valores utilizando uma pilha. Finalmente, os valores da fila
devem ser mostrados. A implementação deve ser feita utilizando-se apenas as operações
dos TAD Fila e Pilha (inserir, remover, pilha_vazia, empilha, etc.), não acesse
diretamente os elementos da struct
*/

#include <stdio.h>
#include <stdlib.h>
#include "dinamica/Fila.h"
#include "Pilha.h"
Fila f;
Pilha p;

int main(){
    
    printf("Quantos valores deseja inserri?");
    int num, val;
    scanf("%d", &num);
    inicializa_fila(&f, num);
    inicializa_pilha(&p, num);

    for(int i = 0; i < num; i++){
        scanf("%d", &val);
        inserir(&f, val);
    }
    printf("\nFila:");
    mostra_fila(f);

    while(!fila_vazia(f)){
        int x;
        remover(&f, &x);
        empilha(&p, x);
    }
    mostra_pilha(p);

    while(!pilha_vazia(p)){
        int x1;
        desempilha(&p, &x1);
        inserir(&f, x1);
    }   
    printf("\nValores finais:\n");
    mostra_fila(f);



    return 1;
}