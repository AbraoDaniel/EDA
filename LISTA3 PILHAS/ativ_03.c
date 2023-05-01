/*
Escreva uma função (em nível de aplicação, ou seja, no arquivo principal do programa)
que utiliza uma pilha para inverter um string. Para isso, basta empilhar todos os seus
caracteres em uma pilha e, em seguida, desempilhar de volta na string.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"

Pilha p;

int main(){
    char str[] = "Algo Assim";

    inicializa_pilha(&p, strlen(str));
    for(int i=0; str[i] != 0; i++){
        empilha(&p, str[i]);
    }
    for (int i = 0; str[i] != 0; i++){
        int aux;
        desempilha(&p, &aux);
        str[i] = aux;
    }
    printf("%s \n", str);
    
    desaloca_pilha(&p);
    return 1;
}