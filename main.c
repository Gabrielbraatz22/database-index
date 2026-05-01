#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

#define MAX 200

void ajuda() {
    printf("\nComandos disponíveis:\n");
    printf("INSERT <id>\n");
    printf("SEARCH <id>\n");
    printf("REMOVE <id>\n");
    printf("RANGE <id1> <id2>\n");
    printf("PRINT\n");
    printf("HELP\n");
    printf("EXIT\n\n");
}

int main() {

    BTree* btree = btree_cria();
    char linha[MAX];

    ajuda();

    while (1) {

        printf("db> ");

        // lê linha inteira (melhor que scanf)
        if (!fgets(linha, MAX, stdin))
            break;

        // remove \n
        linha[strcspn(linha, "\n")] = 0;

        // comando
        char cmd[20];
        int id, a, b;

        // INSERT
        if (sscanf(linha, "INSERT %d", &id) == 1) {
            btree = btree_insere(btree, id);
            printf("Inserido: %d\n", id);
        }

        // SEARCH
        else if (sscanf(linha, "SEARCH %d", &id) == 1) {
            printf("%s\n", btree_busca(btree, id) ? "Encontrado" : "Nao encontrado");
        }

        // REMOVE
        else if (sscanf(linha, "REMOVE %d", &id) == 1) {
            btree = btree_remove(btree, id);
            printf("Removido: %d\n", id);
        }

        // RANGE
        else if (sscanf(linha, "RANGE %d %d", &a, &b) == 2) {
            printf("Range [%d, %d]: ", a, b);
            btree_range(btree, a, b);
            printf("\n");
        }

        // PRINT
        else if (strcmp(linha, "PRINT") == 0) {
            printf("Arvore: ");
            btree_mostra(btree);
            printf("\n");
        }

        // HELP
        else if (strcmp(linha, "HELP") == 0) {
            ajuda();
        }

        // EXIT
        else if (strcmp(linha, "EXIT") == 0) {
            break;
        }

        else {
            printf("Comando inválido. Digite HELP.\n");
        }
    }

    btree_destroi(btree);
    return 0;
}