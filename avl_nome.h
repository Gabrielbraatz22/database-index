#ifndef AVL_NOME_H
#define AVL_NOME_H

typedef struct AVL {
    char nome[50];
    int id;
    int altura;
    struct AVL *esq, *dir;
} AVL;

AVL* avl_insere(AVL* r, char* nome, int id);
int avl_busca(AVL* r, char* nome);

#endif