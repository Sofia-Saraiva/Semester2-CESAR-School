#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char Titulo[50];
    char Autor[50];
    int NumReg;
    double Preco;
    struct Livro* prox;
} Livro;

Livro GetLivro();
void PrintLivro(Livro livro);
Livro* AddLivro(Livro* lista, Livro livro);
Livro* BuscarLivro(Livro* lista, char busca[]);
Livro* RemLivro(Livro* lista, char busca[]);
void ListarLivros(Livro* lista);

#endif
