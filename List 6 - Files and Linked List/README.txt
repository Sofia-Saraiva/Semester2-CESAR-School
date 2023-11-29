Programa de Controle de Estoque de Livros

1. Compilação:
      gcc -o main main.c lista.c

2. Execução:
      ./main

3. Funcionalidades do Programa:
    - Inserir um livro: Permite adicionar um novo livro ao estoque.
    - Buscar um livro: Permite pesquisar um livro por título ou número de registro e exibir suas informações.
    - Remover um livro: Permite remover um livro do estoque com base no título ou número de registro.
    - Listar todos os livros: Exibe a lista de todos os livros no estoque.
    - Salvar em arquivo: Salva os dados do estoque em um arquivo "livros.dat".
    - Sair: Encerra o programa.

4. Modificações no Código Original:
    - Implementação da lista encadeada e funções para dar apoio a lista como: adição de funções para inserção(AddLivro), busca(BuscarLivro), remoção(RemLivro) e parar listar(ListarLivros) todos os livros da lista.
    - Reutilização da função PrintLivro para printar as especificações do livro e GetLivro para pegar as informações do livro.
    - Implementação da função SalvarArquivo e LerArquivo.
    - Criação do arquivo lista.h e lista.c para colocar as funções da lista encadeadas e as funções já existentes em leitura.c

5. Arquivos:
  - main.c
  - lista.c
  - lista.h
