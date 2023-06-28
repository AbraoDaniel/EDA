#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"


void inicializa_conjunto(Conjuntos *p) {
  inicializa_lista(&p->l, sizeof(Lista));
}

int comparador(void *a, void *b) {
  int *primeiro_valor = (int *)a;
  int *segundo_valor = (int *)b;
  return *primeiro_valor - *segundo_valor;
}

int busca_conjunto(Conjuntos conjunto, int x) {
  Elemento *p = conjunto.l.cabeca;
  int indice = 0;
  while (p != NULL) {
    if (busca_valor(*((Lista *)p->info), &x, comparador)){
      return indice;
    }
    p = p->proximo;
    indice++;
  }
  return -1;
}

int tem_o_valor(Conjuntos p, int info) {
  return busca_conjunto(p, info) >= 0;
}

int cria_conjunto(Conjuntos *p, int info) {
  if (tem_o_valor(*p, info))
    return 0;
  Lista *novoConjunto = malloc(sizeof(Lista));
  if (novoConjunto == NULL)
    return 0;
  inicializa_lista(novoConjunto, sizeof(int));
  insere_fim(novoConjunto, &info);
  insere_fim(&p->l, novoConjunto); // mandar com &u->l
  return 1;
}

Lista *retorna_conjunto(Conjuntos *c, int i) {
	Elemento *p = c->l.cabeca;
	int count = 0;
    while(p != NULL) {
        if(count == i) {
          return (Lista *)p->info;
        } else {
          p = p-> proximo;
          count++;
        }
    }
    return NULL;
}

int remove_conjunto(Conjuntos *conjunto, int pos) {
  Lista list;
  inicializa_lista(&list, sizeof(int));
  remove_pos(&conjunto->l, &list, pos);
  return 1;
}

int unindo_conjuntos(Conjuntos *p, int x, int y) {
  int primeira_busca = busca_conjunto(*p, x);
  int segunda_busca = busca_conjunto(*p, y);

  if (primeira_busca < 0 || segunda_busca < 0) {
    return 0; 
  }

  if (primeira_busca == segunda_busca) {
    return 0; 
  }

  Lista *primeiro_conj = retorna_conjunto(p, primeira_busca);
  Lista *segundo_conj = retorna_conjunto(p, segunda_busca);
  concatena(primeiro_conj, segundo_conj);
  remove_conjunto(p, segunda_busca);
  return 1;
}

void mostrar_conjuntos(Conjuntos *u, int n) {
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
