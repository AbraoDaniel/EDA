#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

Pilha p;


int main(){
    inicializa_pilha (&p, 32);
    printf("Digite um numero: \n");
    int num;
    scanf("%d", &num);

    do{
        int resto = num % 2;
        empilha( &p, resto);
        num = num / 2;
    } while (num > 0);

    while(!pilha_vazia(p)){
        int temp;
        desempilha(&p, &temp);
        printf("%d \n", temp);
    }

    return 1;
}