#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pesquisaInterpolacao(int chave, int v[], int n) {
    int ini = 0, meio, fim = n - 1, cont = 1;
    while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
        cont++;
        if(ini == fim) return v[ini] == chave ? ini : -1;
        meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
        cont++;
        if (chave == v[meio]) {
            return cont;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
        cont+=2;
    }
    return cont; //Índice impossível
}

int compara(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

int main () {
    int n = 5;
    int v[n];
    srand(time(0));
    int pesquisa = rand() % 100;

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    qsort(v, n, sizeof(int), compara);

    int buscaInterpolacao = pesquisaInterpolacao(pesquisa, v, n);
   
    printf("NÚMERO DE COMPARAÇÕES BINÁRIA: %d\n\n", buscaInterpolacao);
    
    return 0;
}