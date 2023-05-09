#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Lista.h"
#include "Produto.h"

void mostra_prod( void *x );

int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(struct Produto) );
	
	int n, i;
	scanf("%d", &n);
	
	for( i = 1 ; i <= n ; i++ ){
		struct Produto x;
		gera_dados_produto( &x );
		insere_fim( &l1, &x );
	}
	
	mostra_lista( l1, mostra_prod );
	system("PAUSE");

	//limpa_lista(&l1);
	while(!lista_vazia(l1)){
		struct Produto x;
		remove_fim(&l1, &x);
		printf("Produto Removido:");
		mostra_produto( x );
		mostra_lista(l1, mostra_prod);
		system("PAUSE");
	}
	
	


	return 0;
}

void mostra_prod( void *x ){
	struct Produto *p = x;
	mostra_produto( *p );
}

