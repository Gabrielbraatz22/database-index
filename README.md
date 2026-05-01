Mini Banco de Dados em C
Descrição

Este projeto implementa um mini sistema de indexação de dados utilizando estruturas de dados em C. O objetivo é simular operações básicas de um banco de dados, como inserção, busca, remoção e consultas por intervalo.

Estrutura

A indexação por ID foi implementada utilizando uma árvore binária de busca (BST). Essa estrutura permite organizar os dados de forma eficiente para consultas rápidas.

Funcionalidades

O sistema suporta:

Inserção de registros por ID
Busca de um ID específico
Remoção de registros
Consulta por intervalo de IDs
Visualização da estrutura
Interface

O sistema funciona via linha de comando (CLI), com os seguintes comandos:

INSERT <id>
SEARCH <id>
REMOVE <id>
RANGE <id1> <id2>
PRINT
EXIT
Desempenho

As operações possuem desempenho eficiente em média, porém podem degradar caso a árvore fique desbalanceada.

Limitações

O sistema não utiliza estruturas balanceadas como AVL ou Red-Black, nem implementa uma B-Tree real. Também não há suporte para índices por nome ou email.

Conclusão

O projeto demonstra na prática o uso de estruturas de dados para organização e busca de informações, servindo como base para sistemas mais avançados.
