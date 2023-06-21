#include "Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

int comparador_int(void *a, void *b) {
  int *ia = (int *)a;
  int *ib = (int *)b;
  return *ia - *ib;
}

void inicializa_conjunto(Conjuntos *p) {
  inicializa_lista(&p->l, sizeof(Lista));
}

int busca_conjunto(Conjuntos conjunto, int x) {
  Elemento *p = conjunto.l.cabeca;
  int indice = 0;
  while (p != NULL) {
    if (busca(((Lista *)p->info), &x, comparador_int))
      return indice;
    p = p->proximo;
    indice++;
  }
  return -1;
}

int valor_existente(Conjuntos p, int info) {
  return busca_conjunto(p, info) >= 0;
}

int cria_conjunto(Conjuntos *p, int info) {
  if (valor_existente(*p, info))
    return 0;
  Lista *novoConjunto = malloc(sizeof(Lista));
  if (novoConjunto == NULL)
    return 0;
  inicializa_lista(novoConjunto, sizeof(int));
  insere_fim(novoConjunto, &info);
  insere_fim(&p->l, novoConjunto); // mandar com &u->l
  return 1;
}

Lista *obter_conjunto(Conjuntos *c, int i) {
	Elemento *p = c->l.cabeca;
	int count = 0;
    while(p != NULL) {
        if(count == i)
          return (Lista *)p->info;
        p = p-> proximo;
        count++;
    }
    return NULL;
}

int remove_conjunto_pos(Conjuntos *conjunto, int pos) {
  Lista temp;
  inicializa_lista(&temp, sizeof(int));
  remove_pos(&conjunto->l, &temp, pos);
  return 1;
}

int uniao_conjunto(Conjuntos *p, int x, int y) {
  int ix = busca_conjunto(*p, x);
  int iy = busca_conjunto(*p, y);
  if (ix < 0 || iy < 0)
    return 0; // nao encontrado
  if (ix == iy)
    return 0; // l iguais
  Lista *conjuntoX = obter_conjunto(p, ix);
  Lista *conjuntoY = obter_conjunto(p, iy);
  concatena(conjuntoX, conjuntoY); // tenho ela salva nos trabalhos, achar e colocar em Lista.h
  remove_conjunto_pos(p, iy);
  return 1;
}



