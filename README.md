# Sistema de Gerenciamento de Biblioteca

## Descrição do Projeto
Este é um sistema de gerenciamento de biblioteca desenvolvido em C como parte de um projeto acadêmico. O sistema é baseado em um menu interativo no terminal, permitindo realizar operações de **cadastro**, **busca**, **empréstimo** e **devolução** de livros. O projeto tem como objetivo aplicar conceitos de programação em C, como structs, funções e controle de fluxo.

## Funcionalidades

- **Cadastro de Livros:**  
  Permite cadastrar até 100 livros com informações como título, autor, número de páginas, ano de publicação, código único (ID) e quantidade disponível.

- **Consulta de Livros:**  
  Possibilidade de listar todos os livros cadastrados ou buscar um livro específico por ID ou título.

- **Empréstimo de Livros:**  
  Empréstimo de livros, com atualização automática da quantidade disponível e registro de quem pegou o livro.

- **Devolução de Livros:**  
  Permite a devolução de livros, atualizando a quantidade disponível e removendo o nome da pessoa que fez o empréstimo.

- **Remoção de Livros:**  
  Função para remover livros do sistema.

- **Menu Interativo:**  
  Menu simples e intuitivo no terminal para navegar entre as opções disponíveis.

## Requisitos do Sistema

- **Linguagem:**  
  C (exceto para entrada e saída de dados e manipulação de strings, que usam `std::cin` e `std::cout`).

- **Bibliotecas Padrão:**  
  Utiliza as bibliotecas padrão da linguagem C e C++ para manipulação básica de dados.

## Estrutura do Projeto

- **`main.cpp`**: Arquivo principal com o loop do menu e chamadas de funções.

## Como Usar

O sistema oferece um menu interativo com as seguintes opções:

- **Cadastrar Livro**: Permite adicionar um novo livro à biblioteca.
- **Consultar Livros**: Exibe todos os livros cadastrados ou permite busca por título ou ID.
- **Realizar Empréstimo**: Empréstimo de um livro disponível.
- **Devolver Livro**: Realiza a devolução de um livro e atualiza o sistema.
- **Remover Livro**: Remove um livro do sistema.
- **Sair**: Encerra o programa.

### Exemplo de Uso:

```bash
Bem-vindo ao Sistema de Gerenciamento de Biblioteca!
Escolha uma opção:
1 - Cadastrar Livro
2 - Consultar Livros
3 - Realizar Empréstimo
4 - Devolver Livro
5 - Remover Livro
6 - Sair
```

## Autores

- Bruno Reitano
- João Gabriel
- Pedro Daou
- Pedro Ximenes
- Yuri Cardoso

## Entrega

O projeto deverá ser entregue no Canvas até **1° de Novembro de 2024**. Cada grupo deverá apresentar o sistema funcionando e explicar as principais decisões de implementação.

---

Desenvolvido com 💻 e 📚.
