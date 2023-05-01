#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"

Pilha p;

int main(){
    char str1[] = "arara";
    int tam = strlen(str1);
    char str2[tam];

    inicializa_pilha(&p, tam);

    for(int i=0; str1[i] != 0; i++){
        empilha(&p, str1[i]);
    }

    for(int i=0; str1[i] != 0; i++){
        int aux;
        desempilha(&p, &aux);
        str2[i] = aux;
    }

    printf("%s \n%s\n", str1, str2);

    if(strcmp(str1, str2) == 0)
        printf("PALINDROME \n");
    else
        printf("NÃO PALINDROME\n");
    

    return 1;
}