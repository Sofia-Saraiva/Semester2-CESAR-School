#include "lista.h"

Livro GetLivro() {
  Livro livro;
  printf("\nDigite o título: ");
  fgets(livro.Titulo, sizeof(livro.Titulo), stdin);
  printf("Digite o nome do autor: ");
  fgets(livro.Autor, sizeof(livro.Autor), stdin);
  printf("Digite o número de registro: ");
  scanf("%d", &livro.NumReg);
  printf("Digite o preço do livro: ");
  scanf("%lf", &livro.Preco);
  getchar();

  livro.prox = NULL;
  return livro;
}

void PrintLivro(Livro livro) {
  printf("\nTítulo: %s", livro.Titulo);
  printf("Autor: %s", livro.Autor);
  printf("Número de Registro: %d\n", livro.NumReg);
  printf("Preço: %.2lf\n", livro.Preco);
}

Livro* AddLivro(Livro* lista, Livro livro) {
    Livro* novoLivro = malloc(sizeof(Livro));
    *novoLivro = livro;
    novoLivro->prox = lista;

    if (lista == NULL || strcmp(livro.Titulo, lista->Titulo) <= 0) {
        return novoLivro;
    }

    Livro* atual = lista;
    while (atual->prox != NULL && strcmp(livro.Titulo, atual->prox->Titulo) > 0) {
        atual = atual->prox;
    }

    novoLivro->prox = atual->prox;
    atual->prox = novoLivro;

    return lista;
}

Livro* BuscarLivro(Livro* lista, char busca[]) {
    Livro* atual = lista;
    while (atual != NULL) {
        if (strcmp(busca, atual->Titulo) == 0 || atoi(busca) == atual->NumReg) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Livro* RemLivro(Livro* lista, char busca[]) {
    if (lista == NULL) {
        return lista;
    }

    if (strcmp(busca, lista->Titulo) == 0 || atoi(busca) == lista->NumReg) {
        Livro* temp = lista;
        lista = lista->prox;
        free(temp);
        return lista;
    }

    Livro* atual = lista;
    while (atual->prox != NULL) {
        if (strcmp(busca, atual->prox->Titulo) == 0 || atoi(busca) == atual->prox->NumReg) {
            Livro* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
            return lista;
        }
        atual = atual->prox;
    }

    return lista;
}

void ListarLivros(Livro* lista) {
    if (lista == NULL) {
        printf("A lista de livros está vazia.\n");
        return;
    }

    printf("\nLista de Livros:\n");
    while (lista != NULL) {
        PrintLivro(*lista);
        lista = lista->prox;
    }
}

