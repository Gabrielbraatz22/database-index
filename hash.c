#include <string.h>
#include <stdlib.h>
#include "hash.h"

Node* tabela[SIZE];

int hash(char* str) {
    int h = 0;
    for (int i = 0; str[i]; i++)
        h = (h * 31 + str[i]) % SIZE;
    return h;
}

void hash_insert(char* email, int id) {
    int h = hash(email);

    Node* n = malloc(sizeof(Node));
    strcpy(n->email, email);
    n->id = id;

    n->prox = tabela[h];
    tabela[h] = n;
}

int hash_busca(char* email) {
    int h = hash(email);

    Node* n = tabela[h];
    while (n) {
        if (strcmp(n->email, email) == 0)
            return n->id;
        n = n->prox;
    }
    return -1;
}