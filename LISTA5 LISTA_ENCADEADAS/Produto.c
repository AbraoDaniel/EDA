#include "Produto.h"
#include <stdio.h>
#include <string.h>

char *nomes[] = { "Caderno", "Caneta", "Borracha", "Lapiseira", "Bloco de Notas" };
int num = sizeof( nomes) / sizeof( nomes[0] );

void mostra_produto( struct Produto x ){
    printf("(%d, %s, R$%.2f)\n", x.codigo, x.descricao, x.preco);
}

void gera_dados_produto( struct Produto *p ){
    p->codigo = rand() % 1000 + 1;
    strcpy( p->descricao, nomes[ rand() % num ] );
    p->preco = ( rand() % 1000 + 1 ) / 10.0;
}

int busca_produto( struct Produto v[], int n, int codigo ){
    int i;
    for( i = 0 ; i < n ; i++ )
        if( v[i].codigo == codigo )
            return i; //  Encontrado no índice i.
    
    return -1; // Não encontrado.
}
