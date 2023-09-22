#include <stdio.h>
#include <stdlib.h>

// Dado um vetor de números inteiros v, encontre o primeiro inteiro positivo ausente no
// vetor. Em outras palavras, deve ser retornado o menor inteiro positivo que não existe no
// vetor. A matriz pode conter duplicados e números negativos também. O algoritmo deve
// apresentar complexidade de tempo linear e de espaço constante (pode desconsiderar
// o esforço para ordenação do vetor).
// ○ Exemplo 1, dado v = [3,4,-1,1], a saída esperada é 2
// ○ Exemplo 2, dado v = [1,2,0], a saída esperada é 3


int main() {
    int v[] = {3,4,-1,1,2,5,6,7,8,9,10,11,12,13,14,15};
    int n = 16;
    int numero = 1;
    int achou = 0;

    while(!achou) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(v[j] == numero) {
                    numero++;
                    continue;
                } else {
                    achou = 1;
                }
            }
        }
    }
    printf("NÃO ACHOU O %d!!!", numero);
    printf("deu tanto: %d", strl);

}