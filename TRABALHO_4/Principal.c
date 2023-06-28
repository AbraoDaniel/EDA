#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"
#include "arvore_n_aria.h"

Fila f;

int main()
{
  // DEFININDO TAMANHO DA MATRIZ E ALOCANDO OS VALORES

  int n;
  printf("Defina o tamanho da matriz desejada: ");
  scanf("%d", &n);

  int matriz[n + 1][n + 1];
  printf("\nDigite a matriz:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

  // INFORMANDO VERTICE INICIAL

  int vertice_inicial;
  printf("\nInforme o vértice inicial: ");
  scanf("%d", &vertice_inicial);

  // INICIALIZA VETOR DE STATUS (VS)

  int vs[n];
  for (int i = 1; i <= n; i++)
  {
    vs[i] = 0;
  }

  Arvore t;

  // INICIALIZANDO FILA E ÁRVORE
  inicializa_fila(&f, n);
  inicializa_Arvore(&t, vertice_inicial);
  

  // DEFININDO V[A] COMO DEFINIDO
  // inicia BFS
  vs[vertice_inicial] = 1;
  inserir(&f, vertice_inicial);

  int aux = 0;
  while (!fila_vazia(f)){
    remover(&f, &aux);                 
      for (int j = 1; j <= n; j++){
        if (matriz[aux][j] == 1){

          if (vs[j] == 0){
            vs[j] = 1;
            insere_filho(t, aux, j);
            inserir(&f, j);
          }
        }
      }
    
  }

  printf("\nÁrvore de Distância Mínima: \n");
  gera_xml(t);

  return 0;
}
