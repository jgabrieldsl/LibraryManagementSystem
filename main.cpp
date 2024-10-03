#include <iostream>
#include <cstdlib> // biblioteca para limpar tela
using namespace std;

// Função para limpar a tela
void limparTela(){
    system("clear");
}

// Estrutura para os livros
struct livro {
    char titulo[100];
    char autor[100];
    int num_paginas;
    int ano_publicacao;
    int id;
    int quantidade_disponivel; // Máximo de 10 exemplares
    char nome_emprestaram[10][100]; // Array de nomes -> Máximo 10 nomes c/ tamanho de 100 caracteres.
};

// vetLivro [0] = {'titulo', 'auto', 120, 2024, 1, 2, "João" }

// Estrutura para as pessoas
struct pessoa {
    char nome[100];
    int documento;
    int idade;
};

// O '&' antes do nome do parâmetro indica que estamos acessando diretamente a estrutura, em vez de criar uma cópia dela para realizar as operações necessárias.
void printLivros(livro &livros) {
    cout << "Título: " << livros.titulo << endl;
    cout << "Autor: " << livros.autor << endl;
    cout << "Número de Páginas: " << livros.num_paginas << endl;
    cout << "Ano de publicação: " << livros.ano_publicacao << endl;
    cout << "Id: " << livros.id << endl;
    cout << "Quantidade de Exemplares Dísponiveis: " << livros.quantidade_disponivel << endl;
    cout << "Nome das Pessoas que estão com o livro: ";
    for (int i = 0; i < 10; i++) {
        if (livros.nome_emprestaram[i][0] != '\0') {
            cout << livros.nome_emprestaram[i] << " " << endl;
        }
    }
    cout << "/////////////////////////////////" << endl;
}

// Chamamos 'sz' normalmente. Usamos *sz somente para modificar o conteúdo diretamente.
void printLivrosVet(livro livros[], int sz){
    if (sz > 0) {
        for (int i = 0; i < sz; i++) {
            printLivros(livros[i]);
        }
    } else {
        cout << "Nenhum livro cadastrado!" << endl;
    }
}

void cadastrarLivros(livro livros[], int *sz) { 
    limparTela();
    if (*sz == 100) {
        cout << "Não é possível adicionar mais livros. Limite atingido!";
        return;
    }
    int qtd_pessoas;
    cout << "Titulo: "; cin.getline(livros[*sz].titulo, 100);
    cout << "Autor : "; cin.getline(livros[*sz].autor, 100);
    cout << "Número de páginas: "; cin >> livros[*sz].num_paginas;
    cout << "Ano de publicação: "; cin >> livros[*sz].ano_publicacao;
    cout << "ID: "; cin >> livros[*sz].id;
    cout << "Exemplares dísponiveis: "; cin >> livros[*sz].quantidade_disponivel;
    cout << "Quantas pessoas estão com este livro emprestado atualmente?: "; cin >> qtd_pessoas;
    cin.ignore();
    if (qtd_pessoas > 0) {
        for (int i = 0; i < qtd_pessoas; i++) {
            cout << "Digite o nome da " << i + 1 << "° pessoa que está com o livro: ";
            cin.getline(livros[*sz].nome_emprestaram[i], 100);
        }
    } else if (qtd_pessoas <= 0) {
        for (int i = 0; i < 10; i++) {
            livros[*sz].nome_emprestaram[i][0] = '\0';
        }
    }

    (*sz)++;
}

/*
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
*/

void emprestimoLivros(struct livro livroscadastrados[], int *sz) {
    int opcao;

    cout << "Deseja consultar todos os livros cadastrados? [1/Sim] [2/Não]: ";
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
                if (livroscadastrados[i].id = id_digitado) {
                    printLivros(livroscadastrados[i]);
                    encontrado = true;
                    break;
                }
            }
            
            if (!encontrado) {
                cout << "Livro com o ID: " << id_digitado << " não encontrado." << endl;
            }

        } 
    }
}


void devolucaoLivros(struct livro livroscadastrados[], int *sz) {
    int opcao, id;

    cout << "========== Devolução de livros ==========" << endl;

    cout << "Deseja consultar os livros já cadastrados? [1 / sim] [2 / não]: "; 
    cin >> opcao;

    if (opcao == 1) {
        printLivrosVet(livroscadastrados, *sz); // Imprime na tela os livros cadastrados
    }
    
    while (true) { // loop para caso o usuário desejar devolver um outro livro
        
        cout << "Digite o Id do livro que deseja devolver: ";
        cin >> id;

        bool existe = false; // Utilizado para verificar se o livro já foi cadastrado no sistema ou não
            
        for (int i = 0; i < *sz; i++) { // verificar se o id digitado existe (encontrar o livro percorrendo a lista dos livros) e realiza a devolução
            
            if (id == livroscadastrados[i].id) {
                
                livroscadastrados[i].quantidade_disponivel++;
                
                existe = true;
                
                cout << "Livro devolvido com sucesso!" << endl;
                break;
            }
        }
            
        if(existe){ // "se" "existe" for verdadeiro:
            char nome[100];
            
            cout << "Digite o nome da pessoa que devolveu o livro: ";
            cin >> nome;
            
            for(int i = 0; i < *sz; i++){ // loop para percorrer a lista de livros
                
                if(id == livroscadastrados[i].id){
                    
                    for(int j = 0; j < 10; j++ ){ // loop para percorrer a lista de nomes que pegaram um determinado livro emprestado
                        
                        if(livroscadastrados[i].nome_emprestaram[j] == nome){
                            
                            //livroscadastrados[i].nome_emprestaram[j][0] = '\0'; (ARRUMAR!!!)
                            
                            cout << "Nome removido com sucesso!";
                            break; // Sai do "for" que verifica a lista dos nomes porque o "nome" já foi encontrado e "limpo"
                        }
                    }
                    break; // Sai do "for" que verifica a lista dos livro. Assim que um livro é encontrado e o nome é limpo, não precisa ver os outros livros.
                }
            }
        }
            
        if (!existe) { // "Se" "existe" for diferente de verdadeiro (não encontrou):
            cout << "Livro não encontrado. Tente novamente..." << endl;
            continue; // volta para o inicio do While
        }
            int opcao2;
            cout << "Deseja devolver outro livro? [1 - sim] [2 - não]: ";
            cin >> opcao2;

            if(opcao2 == 1){
                continue; // volta para o inicio do While
            }else{
            cout << "Saindo para o Menu...";
            return; //sai da função e volta para a anterior (Menu)
            }
    }
}


    

/*
void remocaoLivros(struct livro livroscadastrados[], int *sz){
    
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
*/

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
                // consultaLivros(vetLivros, qtd_disponivel); 
                break;
            case 3:
                emprestimoLivros(vetLivros, &qnt_livros);                
                break;
            case 4:
                devolucaoLivros(vetLivros, &qnt_livros);
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
