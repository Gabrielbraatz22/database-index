#ifndef CMAPA_H
#define CMAPA_H

#include "mapa.h"

Mapa* ccria (void);
Mapa* cinsere (Mapa* m, int chave);
int ciguais (Mapa* m1, Mapa* m2);
void cmostra (Mapa* m);
void cdestroi (Mapa *m);

#endif