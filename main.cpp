#include <iostream>
using namespace std;

struct livro {
    char titulo[100];
    char autor[100];
    int num_paginas;
    int ano_publicacao;
    int id;
    int quantidade_disponivel;
    char nome_emprestaram[100];
};

struct pessoa {
    char nome[100];
    int documento;
    int idade;

};

// indexar
void PrintLivros(struct livro dados) {

    cout << "Título: " << dados.titulo << endl;
    cout << "Autor: " << dados.autor << endl;
    cout << "Número de Páginas: " << dados.num_paginas << endl;
    cout << "Id: " << dados.ano_publicacao << endl;
    cout << "Quantidade de Exemplares Dísponiveis: " << dados.quantidade_disponivel << endl;
    cout << "Nome das Pessoas que Emprestaram: " << dados.nome_emprestaram;

}

void cadastrar_livros(struct livro dados[], int *quant_cadastro) { 

    cout << "Titulo: "; cin.getline(dados[*quant_cadastro].titulo, 100);

    cout << "Autor : "; cin.getline(dados[*quant_cadastro].autor, 100);

    cout << "Número de páginas: "; cin >> dados[*quant_cadastro].num_paginas;

    cout << "Id: "; cin >> dados[*quant_cadastro].id;

    cout << "Quantidade dísponivel: "; cin >> dados[*quant_cadastro].quantidade_disponivel;
    
    //cout << "Nome das pessoas que emprestaram: "
}



int main () {
    struct livro vetLivros[100];
    int qtd = 0;
    int opt;
    do  {
        cout << "Bem vindo ao Sistema de Gerenciamento de Biblioteca!" << endl << endl;
        cout << "1. Cadastro de livros" << endl;    
        cout << "2. Consultar livros" << endl;    
        cout << "3. Emprestar livro" << endl;    
        cout << "4. Devolução de livros" << endl;    
        cout << "5. Remoção de livros" << endl;   
        cout << "6. Sair do programa;" << endl;
        cin >> opt;

        switch (opt) {
            case 1:
                cin.ignore();
                cadastrar_livros (vetLivros, &qtd);    
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                cout << "Opção inválida!";
                break;
        }

        cout << endl;
    
    } while (opt != 6);

    return 0;
}