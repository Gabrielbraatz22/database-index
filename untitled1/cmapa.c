#include "cmapa.h"

Mapa* ccria(void) {
    return cria();
}

Mapa* cinsere(Mapa* m, int chave) {
    return insere(m, chave);
}

int ciguais(Mapa* m1, Mapa* m2) {
    return iguais(m1, m2);
}

void cmostra(Mapa* m) {
    mostra(m);
}

void cdestroi(Mapa *m) {
    destroi(m);
}