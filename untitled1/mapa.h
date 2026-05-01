#ifndef MAPA_H
#define MAPA_H

typedef struct smapa Mapa;

Mapa* cria (void);
Mapa* insere (Mapa* m, int chave);
int busca (Mapa *m, int chave);
void destroi (Mapa *m);
void mostra (Mapa *m);

int iguais (Mapa *m1, Mapa *m2);

#endif