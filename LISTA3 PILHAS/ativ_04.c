/*
Uma palavra é dita palíndrome se a sequência de letras que a forma é a mesma, seja ela
lida da esquerda para a direita ou vice-versa. Exemplos: arara, rairar, hanah. Escreva
uma função (definida no mesmo arquivo do programa principal) que indique se uma dada
string é ou não palíndrome. Para isso, é preciso inverter a string empilhando todos os seus
caracteres em uma pilha e, em seguida, desempilhando-os numa nova string. 
*/

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