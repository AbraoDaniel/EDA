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

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n--;
    int cont = 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        cont++;
        if (chave == v[meio]) {
            return meio;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
        cont += 2;
    }
    return cont; //Índice impossível
}

int compara(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


int main() {
    int n = 100000;
    int v[n];
    srand(time(0));
    int pesquisa = rand() % 100;

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    int buscaNormal = pesquisaSequencial(pesquisa, v, n);
    int buscaSentinela = pesquisaSequencialSentinela(pesquisa, v, n);

    qsort(v, n, sizeof(int), compara);

    int buscaBinaria = pesquisaBinaria(pesquisa, v, n);
   
    printf("NÚMERO DE COMPARAÇÕES NORMAL: %d\n", buscaNormal);
    printf("NÚMERO DE COMPARAÇÕES SENTINELA: %d\n", buscaSentinela);
    printf("NÚMERO DE COMPARAÇÕES BINÁRIA: %d\n\n", buscaBinaria);


}