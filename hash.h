#ifndef HASH_H
#define HASH_H

#define SIZE 10007

typedef struct Node {
    char email[50];
    int id;
    struct Node* prox;
} Node;

void hash_insert(char* email, int id);
int hash_busca(char* email);

#endif