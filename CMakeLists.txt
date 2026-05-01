cmake_minimum_required(VERSION 3.20)

# 🔥 SEM acento, SEM espaço
project(database_index C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(database_index
        main.c
        btree.c
        avl_nome.c
        hash.c
)