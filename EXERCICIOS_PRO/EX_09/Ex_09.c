#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Run-length encoding (RLE) é uma forma simples de compressão de textos. A ideia
// desta técnica é representar caracteres repetidos sucessivamente com um contador
// seguido pelo caractere. Dada uma string, retorne o texto resultante da aplicação da
// técnica RLE.
// ○ Exemplo, dada a string "AAAABBBCCDAA", a saída compactada deve ser "4A3B2C1D2A"

int main() {
    int n = 15;
    char t[] = "AAAABBBCCDAACCC";
    char r[n];
    int cont = 1;
    
    // qsort(t, n, sizeof(char), comparaString);

    for(int i = 0; i < n; i++) {
            if(t[i] == t[i+1]) {
                cont++;
            } else {
                printf("%d%c", cont, t[i]);
                cont = 1;
                continue;
            }
    }
    
    printf("\n");
}