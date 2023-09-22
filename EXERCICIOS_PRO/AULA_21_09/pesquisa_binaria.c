#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int n = 1000;
    int v[n];
    srand(time(0));
    int pesquisa = rand() % 100;

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    qsort(v, n, sizeof(int), compara);

    int buscaBinaria = pesquisaBinaria(pesquisa, v, n);
   
    printf("NÚMERO DE COMPARAÇÕES BINÁRIA: %d\n\n", buscaBinaria);
    
    return 0;
}