#include <string.h>
#include <stdlib.h>
#include "avl_nome.h"

int altura(AVL* n) { return n ? n->altura : 0; }

AVL* novo(char* nome, int id) {
    AVL* n = malloc(sizeof(AVL));
    strcpy(n->nome, nome);
    n->id = id;
    n->altura = 1;
    n->esq = n->dir = NULL;
    return n;
}

AVL* avl_insere(AVL* r, char* nome, int id) {
    if (!r) return novo(nome, id);

    if (strcmp(nome, r->nome) < 0)
        r->esq = avl_insere(r->esq, nome, id);
    else
        r->dir = avl_insere(r->dir, nome, id);

    return r;
}

int avl_busca(AVL* r, char* nome) {
    if (!r) return -1;

    int cmp = strcmp(nome, r->nome);

    if (cmp == 0) return r->id;
    if (cmp < 0) return avl_busca(r->esq, nome);
    return avl_busca(r->dir, nome);
}