#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pesquisaSequencial(int chave, int v[], int n) {
  int i;
  int cont = 1;
  for (i = 0; i < n; i++) {
     cont++;
     if (v[i] == chave) {
        return cont;
     }    
     cont++; 
        
    }
     return cont; //índice inválido
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int i = 0;
    int cont = 1;
    v[n] = chave; //A última posição do vetor possui o sentinela
        while (v[i] != chave) {
            i++;
            cont++;
        }
        cont++;
        if (i < n) return i;

    return cont; //Índice inválido
}


int main() {
    int n = 5;
    int v[n];
    srand(time(0));
    int pesquisa = rand() % 100;

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    int buscaNormal = pesquisaSequencial(pesquisa, v, n);
    int buscaSentinela = pesquisaSequencialSentinela(pesquisa, v, n);


    printf("NÚMERO DE COMPARAÇÕES NORMAL: %d\n\n", buscaNormal);
    printf("NÚMERO DE COMPARAÇÕES SENTINELA: %d\n", buscaSentinela);


}