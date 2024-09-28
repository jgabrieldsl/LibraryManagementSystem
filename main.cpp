#include <iostream>
#include <cstdlib> // biblioteca para limpar tela
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

void limparTela(){
    system("clear");
}

// indexar
void printLivros(struct livro livroscadastrados[], int pos) {
    cout << "Título: " << livroscadastrados[pos].titulo << endl;
    cout << "Autor: " << livroscadastrados[pos].autor << endl;
    cout << "Número de Páginas: " << livroscadastrados[pos].num_paginas << endl;
    cout << "Id: " << livroscadastrados[pos].ano_publicacao << endl;
    cout << "Quantidade de Exemplares Dísponiveis: " << livroscadastrados[pos].quantidade_disponivel << endl;
    cout << "Nome das Pessoas que Emprestaram: " << livroscadastrados[pos].nome_emprestaram << endl << endl;
}

void printLivrosVet(struct livro livroscadastrados[], int *sz){
    for (int i = 0; i < *sz; i++) {
        printLivros(livroscadastrados, i);
    }
}

void printUmLivro(struct livro livroscadastrados[], int *sz){
    printLivros(livroscadastrados, i);
    }

void cadastrarLivros(struct livro livroscadastrados[], int *qtd_cadastro) { 
    limparTela();

    cout << "Titulo: "; cin.getline(livroscadastrados[*qtd_disponivel].titulo, 100);
    cout << "Autor : "; cin.getline(livroscadastrados[*qtd_disponivel].autor, 100);
    cout << "Número de páginas: "; cin >> livroscadastrados[*qtd_disponivel].num_paginas;
    cout << "ID: "; cin >> livroscadastrados[*qtd_disponivel].id;
    cout << "Quantidade dísponivel: "; cin >> livroscadastrados[*qtd_disponivel].quantidade_disponivel;
    (*qtd_disponivel)++;
}

int consultaLivros(struct livro livroscadastrados[], int sz) {
    int valor; int id; int titulo;
    
    cout << "Digite (1) para acessar o livro pelo ID ou (2) para título"; 
    if (valor != 1 && valor != 2){
        cout << "Valor inválido. Digite apenas (1) ou (2).";
        return 1;
    } 
    
    if (valor == 1){
        cout << "Agora, digite o ID do livro: "; cin >> id;
        for(int i = 0; i < sz; i++){
            if(livroscadastrados[i].id == id) {
                cout << "Livro encontrado!" <<endl;
                printLivrosVet(livroscadastrados, &sz); //precisa referenciar?
            }
        } cout << "Livro não encontrado pelo ID "<< livroscadastrados[i].id << endl;

    } else if (valor == 2){
        cout << "Agora, digite o título do livro: "; cin >> titulo;
        cin.ignore();
        cin.getline(titulo, 100);
        
        for(int i = 0; i < sz; i++) {
            if(strcmp(livroscadastrados[i].titulo, titulo) == 0){
                printUmLivro(livroscadastrados, &sz); //precisa referenciar?
            }
            
        } cout << "Livro não encontrado pelo Titulo "<< livroscadastrados[i].titulo << endl;
    }

return 0;

}

void emprestimoLivros(struct livro livroscadastrados[], int *sz) {
    int opcao;

    cout << "Deseja consultar os livros cadastrados? [1/Sim] [2/Não]: ";
    cin >> opcao;

    if (opcao == 1) { 
        printLivrosVet(livroscadastrados, *sz);

    } else {
        do {
        cout << "Você quer buscar o livro pelo ID ou nome do livro?: " << endl;
        cout << "(1) ID" << endl;
        cout << "(2) Nome" << endl;
        cin >> opcao;
        } while (opcao != 1 && opcao != 2);

        if (opcao == 1) {
            int id_digitado;
            cout << "Digite o ID do livro: "; cin >> id_digitado;
            bool encontrado = false;
            for (int i = 0; i < *sz; i ++) {
                if (id_digitado == livroscadastrados[i].id) {
                    cout << "Título: " << livroscadastrados[i].titulo << endl;
                    cout << "Autor: " << livroscadastrados[i].autor << endl;
                    cout << "Número de Páginas: " << livroscadastrados[i].num_paginas << endl;
                    cout << "Id: " << livroscadastrados[i].ano_publicacao << endl;
                    cout << "Quantidade de Exemplares Dísponiveis: " << livroscadastrados[i].quantidade_disponivel << endl;
                    cout << "Nome das Pessoas que Emprestaram: " << livroscadastrados[i].nome_emprestaram << endl << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Livro com o ID: " << id_digitado << " não encontrado." << endl;
            }

        } else {
            
        }
    }
}

void devolucaoLivros(struct livro livroscadastrados[], int *quant_disponivel, int sz){
    // Bruno
    int opcao = 0;

    cout << "Deseja consultar os livros cadastrados? [1 / sim] [2 / não]: "; 
    cin >> opcao;

    if(opcao == 1){
        printLivrosVet() // verificar como 
        return;
        
    }else{

    do
    {
        cout << "Você deseja buscar livro pelo ID ou pelo título?: " << endl;
        cout << "(1) ID" << endl;
        cout << "(2) Título" << endl; 
        cin >> opcao;    

        if (opcao != 1 && opcao != 2){
            cout << "Opção Digitada inválida." << endl;
    }
    }while(opcao != 1 && opcao != 2);

    if(opcao == 1){
        int id = 0;
        
        cout << "Digite o ID do livro: ";
        cin >> id;
        //verificar se o que ele digitou existe
        for(int i = 0; i < sz; i++){ //verificar como ficou o "sz"

        
        

        }

    }
       
 }

    
    
}

void remocaoLivros(struct livro livroscadastrados[], *sz){
    
    int opcao;
    int id_requisitado;
    bool encontrou;

    cout << "==========Remover Livros==========" << endl;

    cout << "\nDeseja consultar os livros cadastrados? [1/Sim] [2/Não]: " << endl;
    cin >> opcao;

    if (opcao == 1)
    {
        printLivrosVet(livroscadastrados, *sz);
        return;
    } 
    else
    {
        cout << "\nDigite o identificador para remover o livro: " << endl;
        cin >> id_requisitado;




        for (int i = id_requisitado; i < *sz - 1; i++) {
            livroscadastrados[i] = livroscadastrados[i + 1];
        }

        (*sz)--;
        
        cout << "Livro Removido!" << endl;
    }

}


int main () {
    struct livro vetLivros[100];
    int qnt_disponivel = 0;
    int qnt_livros = 0;
    int opcao = 0;
    
    do  {
        cout << "\n\tMenu Sistema de Gerenciamento de Biblioteca!" << endl << endl;
        cout << "Escolha uma opção: " << endl;
        cout << "1. Cadastro de livros" << endl;    
        cout << "2. Consultar livros" << endl;    
        cout << "3. Emprestar livro" << endl;    
        cout << "4. Devolução de livros" << endl;    
        cout << "5. Remoção de livros" << endl;   
        cout << "6. Sair do programa" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cin.ignore();
                cadastrarLivros (vetLivros, &qnt_livros);    
                break;
            case 2:
                cin.ignore();
                consultaLivros(vetLivros, qtd_disponivel); 
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Até logo...";
                break;
            default:
                cout << "Opção inválida!";
                break;
        }

        cout << endl;
    
    } while (qnt_livros != 6);

    return 0;
}