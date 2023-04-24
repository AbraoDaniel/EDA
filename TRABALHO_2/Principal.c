#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    // Entrada de dados
    int n, e, s;
    printf("Qual será o tamanho de sua matriz?");
    scanf("%d", &n);
    int m[n][n];

    printf("Entre com os valores da matriz:\n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    printf("Qual o ponto inicial do percurso? ");
    scanf("%d", &e);

    printf("Onde quer chegar? ");
    scanf("%d\n", &s);

    bool vs[n];
    bool va[n];


    return EXIT_SUCCESS;
}