#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

BTree* btree_cria(void) {
    return NULL;
}

static BTree* novo(int chave) {
    BTree* n = malloc(sizeof(BTree));
    n->chave = chave;
    n->esq = n->dir = NULL;
    return n;
}

BTree* btree_insere(BTree* t, int chave) {
    if (!t) return novo(chave);

    if (chave < t->chave)
        t->esq = btree_insere(t->esq, chave);
    else if (chave > t->chave)
        t->dir = btree_insere(t->dir, chave);

    return t;
}

int btree_busca(BTree* t, int chave) {
    if (!t) return 0;

    if (chave == t->chave) return 1;

    if (chave < t->chave)
        return btree_busca(t->esq, chave);
    else
        return btree_busca(t->dir, chave);
}

static BTree* menor(BTree* t) {
    while (t->esq) t = t->esq;
    return t;
}

BTree* btree_remove(BTree* t, int chave) {
    if (!t) return NULL;

    if (chave < t->chave)
        t->esq = btree_remove(t->esq, chave);
    else if (chave > t->chave)
        t->dir = btree_remove(t->dir, chave);
    else {
        if (!t->esq) {
            BTree* tmp = t->dir;
            free(t);
            return tmp;
        }
        else if (!t->dir) {
            BTree* tmp = t->esq;
            free(t);
            return tmp;
        }

        BTree* tmp = menor(t->dir);
        t->chave = tmp->chave;
        t->dir = btree_remove(t->dir, tmp->chave);
    }

    return t;
}

void btree_range(BTree* t, int a, int b) {
    if (!t) return;

    if (t->chave > a)
        btree_range(t->esq, a, b);

    if (t->chave >= a && t->chave <= b)
        printf("%d ", t->chave);

    if (t->chave < b)
        btree_range(t->dir, a, b);
}

void btree_mostra(BTree* t) {
    if (!t) return;

    btree_mostra(t->esq);
    printf("%d ", t->chave);
    btree_mostra(t->dir);
}

void btree_destroi(BTree* t) {
    if (!t) return;

    btree_destroi(t->esq);
    btree_destroi(t->dir);
    free(t);
}