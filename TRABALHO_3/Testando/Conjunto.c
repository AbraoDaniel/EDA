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
    if (busca_valor(*((Lista *)p->info), &x, comparador_int)){
      return indice;
    }
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


int remove_conjunto(Conjuntos *conjunto, int pos) {
  Lista temp;
  inicializa_lista(&temp, sizeof(int));
  remove_pos(&conjunto->l, &temp, pos);
  return 1;
}

int uniao_conjunto(Conjuntos *p, int x, int y) {
  int ix = busca_conjunto(*p, x);
  int iy = busca_conjunto(*p, y);

  if (ix < 0 || iy < 0)
    return 0; 

  if (ix == iy)
    return 0; 

  Lista *primeiro_conj = obter_conjunto(p, ix);
  Lista *segundo_conj = obter_conjunto(p, iy);
  concatena(primeiro_conj, segundo_conj);
  remove_conjunto(p, iy);
  return 1;
}

void mostrarConjuntos(Conjuntos *u, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j, elemen = 0;
        for (j = 0; j < n; j++) {
            if (busca_conjunto(*u, j) == i) {
                elemen = 1;
            }
        }
        if (elemen) {
            for (j = 0; j < n; j++) {
                if (busca_conjunto(*u, j) == i) {
                    printf("%d ", j+1);
                }
            }
        printf("\n");
    }
}}
