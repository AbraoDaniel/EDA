#include <stdlib.h>
#include <stdio.h>

void printa_jogo(int velha[3][3]);

int main(){
    int j1[1], j2[1];
    int velha[3][3] = {0, 0, 0}, pos[1][1];

    printf("Jogo terá jogadores com peça 1 e 2\n");
    printa_jogo(velha);
    scanf("%d %d", &pos[i][j]);

    return 0;
}

void printa_jogo(int velha[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            printf("| %d |", velha[i][j]);
        }
        printf("\n");
    }
}