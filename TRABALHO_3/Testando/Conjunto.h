#include "Lista.h"

typedef struct {
    Lista l;
} Conjuntos;

void inicializa_conjunto(Conjuntos *p);

int cria_conjunto (Conjuntos *p, int x);

int busca_conjunto(Conjuntos conjunto, int x);

int unindo_conjuntos(Conjuntos *u, int x, int y);

void mostrar_conjuntos(Conjuntos *u, int n); 

int remove_conjunto(Conjuntos *conjunto, int pos);

int tem_o_valor(Conjuntos u, int info);

int comparador(void *a, void *b);

Lista *obter_conjunto(Conjuntos *c, int i);




