#include "Lista.h"
#define MAX_VERTICES 100

typedef struct {
    Lista l;
} Conjuntos;

void inicializa_conjunto(Conjuntos *p);

int cria_conjunto (Conjuntos *p, int x);

int valor_existente(Conjuntos u, int info);

int comparador_int(void *a, void *b);

void desaloca_uniao(Conjuntos *u);

int busca_conjunto(Conjuntos conjunto, int x);

Lista *obter_conjunto(Conjuntos *c, int i);

int remove_conjunto_pos(Conjuntos *conjunto, int pos);

int uniao_conjunto(Conjuntos *u, int x, int y);
