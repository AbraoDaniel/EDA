/*
Implemente uma nova biblioteca de Filas, contendo os seguintes campos: dados (ponteiro
int, capacidade e fim. Esta fila não é circular, sendo que o fim é variável (índice), mas o
início é fixo na posição 0 do vetor. Portanto, é preciso mover os dados para a esquerda a
cada remoção da fila

FIM = ( inicio + n ) % MAX
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"

Fila f;


int main(){
    printf("Qual o tamanho da lista? ");
    int x, aux;
    scanf("%d", &x);
    char fila[x];
    inicializa_fila(&f, x);

    for(int i=0; i < x; i++){
        scanf("%d", &aux);
        inserir(&f, aux);
    }
    mostra_fila(f);

    printf("REMOVENDO VALOR DA FILA!\n\n");
    remover(&f, &aux);
    mostra_fila(f);

    return 1;
}