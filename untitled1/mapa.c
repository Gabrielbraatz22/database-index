#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

struct smapa {
  int kp, kg;
  struct smapa *pai;
  struct smapa *esq, *meio, *dir;
};

Mapa* cria(void) {
  return NULL;
}

static Mapa* novoNo(int chave) {
  Mapa *m = (Mapa*) malloc(sizeof(struct smapa));
  if (!m) exit(1);

  m->kp = chave;
  m->kg = -1;
  m->pai = NULL;
  m->esq = m->meio = m->dir = NULL;

  return m;
}

Mapa* insere(Mapa* m, int chave) {
  if (m == NULL) {
    m = novoNo(chave);
    m->pai = novoNo(-1);
    return m;
  }

  if (chave < m->kp) {
    if (!m->esq) {
      m->esq = novoNo(chave);
      m->esq->pai = m;
    } else {
      insere(m->esq, chave);
    }
  } else {
    if (!m->meio) {
      m->meio = novoNo(chave);
      m->meio->pai = m;
    } else {
      insere(m->meio, chave);
    }
  }

  return m;
}

int busca(Mapa *m, int chave) {
  if (!m) return 0;

  if (m->kp == chave || m->kg == chave)
    return 1;

  return busca(m->esq, chave) ||
         busca(m->meio, chave) ||
         busca(m->dir, chave);
}

void destroi(Mapa *m) {
  if (m) {
    destroi(m->esq);
    destroi(m->meio);
    destroi(m->dir);
    free(m);
  }
}

static void mostra_int(Mapa *m) {
  printf("[");
  if (m) {
    printf("%d:%d ", m->kp, m->kg);
    mostra_int(m->esq);
    mostra_int(m->meio);
    if (m->kg != -1)
      mostra_int(m->dir);
  }
  printf("]");
}

void mostra(Mapa *m) {
  mostra_int(m);
  printf("\n");
}

int iguais(Mapa *m1, Mapa *m2) {
  if (!m1 && !m2) return 1;
  if (!m1 || !m2) return 0;

  return (m1->kp == m2->kp) &&
         (m1->kg == m2->kg) &&
         iguais(m1->esq, m2->esq) &&
         iguais(m1->meio, m2->meio) &&
         iguais(m1->dir, m2->dir);
}