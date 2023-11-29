#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void SalvarArquivo(Livro *lista);
Livro* LerArquivo();

int main(void) {
  Livro *lista = LerArquivo();

  printf("Sistema de estoque de livros da livraria\n");

  while (1) {
    printf("\nMenu:\n1. Inserir um livro\n2. Buscar um livro por título ou "
           "número de registro\n3. Remover um livro\n4. Listar todos os "
           "livros\n5. Salvar em arquivo\n6. Sair\nEscolha uma opção: ");

    int escolha;
    scanf("%d", &escolha);
    getchar();

    switch (escolha) {
    case 1:
      lista = AddLivro(lista, GetLivro());
      SalvarArquivo(lista);
      break;
    case 2:
      printf("\nDigite o título ou número de registro a ser buscado: ");
      char busca[50];
      fgets(busca, sizeof(busca), stdin);
      Livro *encontrado = BuscarLivro(lista, busca);
      if (encontrado) {
        PrintLivro(*encontrado);
      } else {
        printf("Livro não encontrado.\n");
      }
      break;
    case 3:
      printf("\nDigite o título ou número de registro a ser removido: ");
      char remocao[50];
      fgets(remocao, sizeof(remocao), stdin);
      lista = RemLivro(lista, remocao);
      SalvarArquivo(lista);
      break;
    case 4:
      ListarLivros(lista);
      break;
    case 5:
      SalvarArquivo(lista);
      break;
    case 6:
      printf("Programa encerrado.\n");
      free(lista);
      return 0;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }
}

Livro *LerArquivo() {
  FILE *fptr = fopen("livros.dat", "rb");
  if (fptr == NULL) {
    return NULL;
  }

  Livro *lista = NULL;
  Livro livro;

  while (fread(&livro, sizeof(Livro), 1, fptr) == 1) {
    lista = AddLivro(lista, livro);
  }

  fclose(fptr);
  return lista;
}

void SalvarArquivo(Livro *lista) {
  FILE *fptr = fopen("livros.dat", "wb");
  if (fptr == NULL) {
    return;
  }

  while (lista != NULL) {
    if (fwrite(lista, sizeof(Livro), 1, fptr) != 1) {
      fclose(fptr);
      return;
    }
    lista = lista->prox;
  }

  fclose(fptr);
}
