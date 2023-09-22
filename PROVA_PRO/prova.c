#include <stdio.h>
#include <stdlib.h>

int main() {
    int luvas[] = {6,5,2,3,5,2,2,1};
    int n = 8;
    int cont = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++){
            if(luvas[i] == luvas[j] && i != j) {
                cont++;
            }
        }
    }

    int pares = cont/4;

    printf("Máximo de pares existentes no conjunto: %d\n", pares);
}