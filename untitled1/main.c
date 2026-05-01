#include <stdio.h>
#include "mapa.h"
#include "cmapa.h"

int main(void) {

    int chave;

    Mapa *mapacand = cria();
    Mapa *mapagab = ccria();

    while (1) {
        printf("chave (-111 para sair): ");
        scanf("%d", &chave);

        if (chave == -111) break;

        mapacand = insere(mapacand, chave);
        mapagab = cinsere(mapagab, chave);

        printf("Aluno:\n");
        mostra(mapacand);

        printf("Gabarito:\n");
        cmostra(mapagab);

        if (!ciguais(mapagab, mapacand)) {
            printf("ERRO!\n");
            break;
        } else {
            printf("OK!\n");
        }
    }

    destroi(mapacand);
    cdestroi(mapagab);

    return 0;
}