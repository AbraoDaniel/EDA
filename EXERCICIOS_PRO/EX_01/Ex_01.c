#include <stdio.h>
#include <stdlib.h>

// Dado um vetor de números inteiros v de tamanho n e um número k, retorne verdadeiro
// se a soma de qualquer par de números em v for igual a k.
// ○ Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17


int main() {
  int v[] = {10,15,3,7};
  int n = 4;
  int k = 17;
    
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++){
        if(v[i] + v[j] == k) {
            printf("Achou: %d + %d = %d\n", v[i], v[j], k);
            return 1;
        }
    }
  }

  printf("Não achou!\n");
}