#include "Fila.h"
#include <stdio.h>

void inicializa_fila( Fila *p ){
	p->inicio = p->n = 0;
}

int fila_vazia( Fila f ){
	return f.n == 0;
}

int fila_cheia( Fila f ){
	return f.n == MAX;
}

int inserir( Fila *p, int info ){
	if( fila_cheia( *p ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( p->inicio + p->n ) % MAX;
	p->dados[fim] = info;
	p->n++;
	return 1; // Sucesso.
}


int remover( Fila *p, int *info ){
	if( fila_vazia( *p ) )
		return ERRO_FILA_VAZIA;
	
	*info = p->dados[p->inicio];
	p->inicio = ( p->inicio + 1 ) % MAX;
	p->n--;
	return 1; // Sucesso.
}

void mostra_fila( Fila f ){
	if( fila_vazia( f ) )
		printf("Fila Vazia!\n");
	else{
		printf("Dados da Fila:\n");
		int cont, i;
		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = ( i + 1) % MAX )
			printf("[%d] %d\n", i, f.dados[i]);
	}
	printf("---------------\n\n");
}

