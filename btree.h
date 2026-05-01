#ifndef BTREE_H
#define BTREE_H

typedef struct BTree {
    int chave;
    struct BTree *esq;
    struct BTree *dir;
} BTree;

BTree* btree_cria(void);
BTree* btree_insere(BTree* t, int chave);
int btree_busca(BTree* t, int chave);
BTree* btree_remove(BTree* t, int chave);

void btree_range(BTree* t, int a, int b);
void btree_mostra(BTree* t);
void btree_destroi(BTree* t);

#endif