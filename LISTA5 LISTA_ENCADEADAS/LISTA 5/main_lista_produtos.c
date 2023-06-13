#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void mostra_prod( void *x );
int compara_descricao( void *x, void *y );
int compara_codigo( void *x, void *y );

int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(struct Produto) );
	
	int op, pos;
	struct Produto x;
	
	do{
		system("CLS");
		printf("1-Visualizar\n2-Inserir (em ordem)\n3-Remover\n");
		printf("4-Ler valor\n5-Modificar\n6-Sair\n");
		scanf("%d", &op);
		switch( op ){
			case 1:
				mostra_lista( l1, mostra_prod );
				system("PAUSE");
				break;
				
			case 2:
				gera_dados_produto( &x );
				printf("O seguinte produto foi inserido: ");
				mostra_produto( x );
				
				insere_ordem( &l1, &x, compara_codigo );
				
				system("PAUSE");
				break;
				
			case 5:
				printf("Digite o indice: ");
				scanf("%d", &pos);
				gera_dados_produto( &x );
				if( modifica_valor( l1, &x, pos ) == ERRO_POS_INVALIDA)
					printf("%d eh um indice invalido!\n", pos);
				else{
					printf("O seguinte produto foi atualizado (indice %d): ", pos);
					mostra_produto( x );
				}
				system("PAUSE");
				break;
		}
		
		
	}while( op != 6 );
	
	
	limpa_lista( &l1 );
	
	
		
	return 0;
}

void mostra_prod( void *x ){
	struct Produto *p = x;
	mostra_produto( *p );
}

int compara_descricao( void *x, void *y ){
	struct Produto *a = x, *b = y;
	return strcmp( a->descricao, b->descricao );
}

int compara_codigo( void *x, void *y ){
	struct Produto *a = x, *b = y;
	return a->codigo - b->codigo;
}

