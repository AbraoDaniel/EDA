#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(int argc, char *argv[]) {
	Fila f1;
	inicializa_fila( &f1 );
	mostra_fila( f1 );
	
	inserir( &f1, 3 );
	mostra_fila( f1 );
	
	inserir( &f1, 6 );
	mostra_fila( f1 );
	
	inserir( &f1, 9 );
	mostra_fila( f1 );
	
	inserir( &f1, 12 );
	mostra_fila( f1 );
	
	int x;
	remover( &f1, &x );
	//printf("X = %d\n", x);
	//mostra_fila( f1 );
	remover( &f1, &x );
	//printf("X = %d\n", x);
	//mostra_fila( f1 );
	
	inserir( &f1, 15 );
	inserir( &f1, 18 );
	mostra_fila( f1 );
	
	return 0;
}
