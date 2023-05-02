/*
Faça um programa que verifique se uma expressão aritmética contém os parênteses
organizados aos pares (utilizando apenas as operações da pilha). O programa lê uma
string, por exemplo "((2 + 4) * 6) / 3"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

Pilha p;

int main(int argc, char *argv[]) {
    char exp[] = "((2+4)*6)/3";
    int tam= strlen(exp);
    int i, lixo;
    inicializa_pilha(&p, tam);

    for(i=0; exp[i] != 0; i++){
        if(exp[i]=='('){
            empilha(&p, exp[i]);
        } else
        if(exp[i]==')'){
            if(pilha_vazia(p)){
                printf("Fecha sem abre\n");
                return 1;
            }else{
                desempilha(&p, &lixo);
            }
        }
    }
    if(!pilha_vazia(p)){
            printf("Parenteses aberto e não fechado\n");
        }else{
             printf("Expressão ok!\n");
        }
    desaloca_pilha(&p);

    return 1;
}