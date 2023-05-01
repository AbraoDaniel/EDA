/*
Escreva um programa em C que converta um número decimal para binário. Dado um
número inteiro n, a conversão é feita de seguinte forma: divida sucessivamente n por 2,
guardando os restos das divisões, até obter um quociente igual a 0. Os restos dessas
divisões representam os dígitos (0 ou 1) do número binário gerado. No entanto, tais
dígitos são gerados na ordem inversa (do menos para o mais significativo). Portanto, o
programa deve usar uma pilha para guardar os restos das divisões que, quando
desempilhados e mostrados na tela, representam corretamente o número binário gerado
*/

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