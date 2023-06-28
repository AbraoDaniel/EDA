#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"
#include "arvore_n_aria.h"

Fila f;

int main()
{
  FILE *arquivo;

  arquivo = fopen("arquivo.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo");
    return 1;
  }

  // DEFININDO TAMANHO DA MATRIZ E ALOCANDO OS VALORES

  int n;
  printf("Defina o tamanho da matriz desejada: ");
  scanf("%d", &n);

  int matriz[n + 1][n + 1];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      fscanf(arquivo, "%d", &matriz[i][j]);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int valor;
      printf("%4d", matriz[i][j]);
    }
    printf("\n");
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
