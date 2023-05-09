#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "Lista.h"

//Privado------------------------

Elemento *aloca_elemento( void *info, int tam ) {
	Elemento *p = malloc( sizeof(Elemento) );
	if( p == NULL )
		return NULL; // Erro, falta de mem�ria!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de mem�ria!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_lista( Lista *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia ( Lista l ){
	return l.cabeca == NULL;
}

int insere_inicio( Lista *p, void *info ){
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de mem�ria!

	novo->proximo = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_inicio( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	Elemento *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->proximo;
	free( aux->info );
	free( aux );
	p->qtd--;
	return 1; // Sucesso!
}


void mostra_lista( Lista l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista (%d elementos):\n", l.qtd );
		Elemento *p = l.cabeca;
		int cont = 0; // cont � o �ndice do elemento dentro da lista.
		while( p != NULL ){
			printf("[%d] ", cont);
			mostra( p->info ); // Invoca��o por callback
			p = p->proximo;
			cont++;
		}
	}
	printf("--------------------------------\n");
}


/*
// ------------
int conta_elementos(lista l){
	int cont = 0;
	elemento *p = l.cabeca;
	while(p!=NULL){
		cont++;
		p = p->proximo;
	}
	return cont;
}

*/
void limpa_lista(Lista *p){ // desaloca memoria
	Elemento *aux = p->cabeca;
	while(aux!=NULL){
		Elemento *prox = aux->proximo; 
		free(aux->info);
		free(aux);
		aux = prox;
	}
	inicializa_lista(p, p-> tamInfo);
}

int insere_fim(Lista *p, void *info){
	if(lista_vazia(*p)){
		return insere_inicio(p, info);
	}

	Elemento *aux = p->cabeca; // percorre a lista!

	while(aux->proximo != NULL){ // vai até o final da lista
		aux = aux->proximo;
	}
	
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if(novo == NULL)
		return 0; //ERRO FALTA DE MEMORIA

	aux->proximo = novo;
	novo->proximo = NULL;
	p->qtd++;
	return 1;
}

int remove_fim(Lista *p, void *info){
	if(lista_vazia(*p)){
		return ERRO_LISTA_VAZIA;
	}

	if(p->qtd == 1) // se só tem 1 elemento na lista!
		return remove_inicio(p, info);

	Elemento *aux = p->cabeca; // percorre a lista!

	while(aux->proximo->proximo != NULL)
		aux = aux -> proximo;

	Elemento *ultimo = aux->proximo;
	memcpy(info, ultimo->info, p->tamInfo); // destinoi, origem, num de bites		
	free(ultimo->info);
	free(ultimo);

	aux->proximo = NULL;
	p-> qtd--;
	return 1; // sucesso
}