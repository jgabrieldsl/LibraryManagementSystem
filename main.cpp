#include <iostream>
#include <cstdlib> // biblioteca para limpar tela
#include <cstring>
#include <string.h>
using namespace std;

// Função para limpar a tela
void limparTela() {
    system("clear");
}

// Estrutura para as pessoas
struct pessoa {
    char nomeCliente[100];
    char CPF[12];
};

// Estrutura para os livros
struct livro {
    char titulo[100];
    char autor[100];
    int num_paginas;
    int ano_publicacao;
    int id;
    int quantidade_disponivel; // Máximo de 10 exemplares
    int qnt_emprestaram = 0;
    pessoa emprestaram[10]; // Array de nomes -> Máximo 10 nomes c/ tamanho de 100 caracteres.
};

// vetLivro [0] = {'titulo', 'auto', 120, 2024, 1, 2, "João" }

// O '&' antes do nome do parâmetro indica que estamos acessando diretamente a estrutura, em vez de criar uma cópia dela para realizar as operações necessárias.
void printLivros(livro livros) {
    cout << "Título: " << livros.titulo << endl;
    cout << "Autor: " << livros.autor << endl;
    cout << "Número de Páginas: " << livros.num_paginas << endl;
    cout << "Ano de publicação: " << livros.ano_publicacao << endl;
    cout << "Id: " << livros.id << endl;
    cout << "Quantidade de Exemplares Dísponiveis: " << livros.quantidade_disponivel << endl;
    cout << "Nome das Pessoas que estão com o livro: " << endl << endl;
    
    for (int i = 0; i < 10; i++) {
        if (livros.emprestaram[i].nomeCliente[0] != '\0') {
            cout << "Nome: "<< livros.emprestaram[i].nomeCliente << " CPF: ";
            for(int j = 0; j < 11; j++){
            cout << livros.emprestaram[i].CPF[j];
            }
            cout << endl;
        }
    }
    cout << "/////////////////////////////////" << endl << endl;
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
    
    while(true) {
        limparTela();
        
        cout << "\n\t===== CADASTRAR LIVRO =====" << endl << endl;
        
        if (*sz == 100) {
            cout << "Não é possível adicionar mais livros. Limite atingido!";
            return;
        }
        cout << "Titulo: "; cin.getline(livros[*sz].titulo, 100);
        cout << "Autor : "; cin.getline(livros[*sz].autor, 100);
        cout << "Número de páginas: "; cin >> livros[*sz].num_paginas;
        cout << "Ano de publicação: "; cin >> livros[*sz].ano_publicacao;
        cout << "ID: "; cin >> livros[*sz].id;
        cout << "Exemplares dísponiveis: "; cin >> livros[*sz].quantidade_disponivel;
        
        cout << "Livro cadastrado com sucesso!" << endl << endl;
        (*sz)++;
        
        int opcao2;
        cout << "Deseja cadastrar outro livro? \n [1-Sim | 2-Não]: ";
        cin >> opcao2;
    
        if (opcao2 == 1){
            cin.ignore();
            continue; // Volta para o inicio do While
            
        } else{  
            limparTela();
            return; //sai da função e volta para a anterior (Menu)
        }
    }
}

void consultaLivros(struct livro livros[], int sz) {
    int valor, id;
    char titulo_desejado[100];
        
    while(true){
        limparTela();
        cout << "\n\t===== CONSULTA LIVROS =====" << endl << endl;
        
        
        cout << "Digite (1) para listar todos os livro, (2) para buscar por ID ou (3) para buscar por título: "; 
        cin >> valor; 
        
        if(valor != 1 && valor != 2 && valor != 3)
            continue;
    
    if (sz == 0) {
        int opc;
        cout << "\nNão há livros cadastrado no momento." << endl << endl;

        cout << "Deseja voltar para o menu? \n[1 -sim | 2 -não]: "; cin >> opc;
        
        if(opc == 1){
            limparTela();
            return;
        } else{
            cout << "\nEncerrando...";
            exit(0);
        }
    }
    
    // Imprimindo todas os livros
    if (valor == 1) {
        for (int i = 0; i < sz; i++){
            limparTela();
            printLivrosVet(livros,sz);
        }
    }
    if (valor == 2) {
        cout << "Agora, digite o ID do livro: "; cin >> id;
            for (int i = 0; i <= sz; i++){
                if (livros[i].id == id) {
                    cout << endl << "Livro encontrado!" << endl;
                    printLivrosVet(livros, 1);
                    break;
                }
                else if (i == sz and livros[i].id != id) {
                    cout << endl  << "Livro não encontrado pelo ID "<< id << endl;
                    break;    
                }
            } 
    
        } else if (valor == 3) {
            cout << "Agora, digite o título do livro: ";
            cin.ignore();
            cin.getline(titulo_desejado, 100);
            
            for (int i = 0; i < sz; i++) {
                if (strcmp(livros[i].titulo, titulo_desejado) == 0) {
                    cout << "Livro encontrado!" <<endl;
                    printLivrosVet(livros, 1);
                    break;
                }
                else if(i == sz and strcmp(livros[i].titulo, titulo_desejado) != 0) {
                    cout << "Livro não encontrado pelo Titulo "<< titulo_desejado << endl;
                    break;    
                }
            }
        }
        
        int opcao2;
        cout << "Deseja consultar outro livro? \n[1-Sim | 2-Não]: ";
        cin >> opcao2;

        if (opcao2 == 1) {
            continue; // volta para o inicio do While
        } else {
            limparTela();
            return; // volta para o Menu
        }
        
    }     
}

void emprestimoLivros(struct livro livros[], int sz) {
    int opcao;

    while (true){
        limparTela();
        cout << "\n\t===== EMPRESTIMOS DE LIVROS =====" << endl << endl;
        
        cout << "Deseja consultar todos os livros cadastrados? \n[1-Sim | 2-Não]: ";
        cin >> opcao;
    
        if (opcao == 1) { 
            printLivrosVet(livros, sz);
        }
    
        int id_digitado;
        bool existe = false;
        
        cout << "Digite o ID do livro para realizar busca: ";
        cin >> id_digitado;
        
        for (int i = 0; i < sz; i++) { // loop para percorrer a lista de livros
            if (id_digitado == livros[i].id) {
                existe = true;
                if (livros[i].qnt_emprestaram == 10){
                    cout << "Limite de empréstimos para este livro atingido." << endl;
                    return;
                } else {
                    cout << "Digite o nome da pessoa que deseja pegar o livro emprestado: ";
                    cin.ignore();
                    cin.getline(livros[i].emprestaram[livros[i].qnt_emprestaram].nomeCliente, 100);
                    
                     cout << "Digite o CPF: ";
                     cin.getline(livros[i].emprestaram[livros[i].qnt_emprestaram].CPF, 12);
                    
                    (livros[i].qnt_emprestaram)++;
                    livros[i].quantidade_disponivel--;
                    cout << "Livro emprestado com sucesso!" << endl;
                    break;
                }
            } 
        }
        
        if (!existe){
            cout << "Livro não encontrado. Tente novamente." << endl;
        }
    
        int opcao2;
        cout << "Deseja emprestar outro livro? \n[1-Sim | 2-Não]: ";
        cin >> opcao2;

        if (opcao2 == 1) {
            continue; // volta para o inicio do While
        } else {
            limparTela();
            return; // volta para o Menu
        }
    }
        
}



void devolucaoLivros(struct livro livros[], int sz) {
    int opcao, id;

    while (true) { // loop para caso o usuário desejar devolver um outro livro
        limparTela();
        cout << "\n\t===== DEVOLUÇÃO DE LIVROS =====" << endl;
    
        cout << "Deseja consultar os livros já cadastrados? \n[1-Sim | 2-Não]: "; 
        cin >> opcao;
    
        if (opcao == 1) {
            printLivrosVet(livros, sz); // Imprime na tela os livros cadastrados
        }
    
        cout << "Digite o ID do livro que deseja devolver: ";
        cin >> id;

        bool existe = false; // verificar se o livro já foi cadastrado no sistema ou não
        bool pessoa_encontrada = false; // verificar se a pessoa foi encontrada 
        
        for (int i = 0; i < sz; i++) { // loop para percorrer a lista de livros
            if (id == livros[i].id) { // verificação do id digitado com o id do livro guardado
                existe = true;
                
                if (livros[i].qnt_emprestaram == 0) {
                    cout << "Não há pessoas que pegaram o livro emprestado no momento." << endl;
                    return;
                }
        
                char nome[100];
                cout << "Digite o nome da pessoa que devolveu o livro: ";
                cin.ignore();
                cin.getline(nome, 100);
                
                char CPF[12]; // Variável para armazenar o CPF
                cout << "Digite o CPF da pessoa: ";
                cin.getline(CPF, 12); // Obtendo o CPF da pessoa
                
                for (int j = 0; j < livros[i].qnt_emprestaram ; j++) { // loop para percorrer a lista de nomes que pegaram um determinado livro emprestado
                    // Compara o nome e o CPF para encontrar a pessoa
                    if (strcmp(livros[i].emprestaram[j].nomeCliente, nome) == 0 &&
                        (strcmp(livros[i].emprestaram[j].CPF, CPF) == 0)) {
                        pessoa_encontrada = true;

                        for (int k = j; k < livros[i].qnt_emprestaram - 1; k++) { // loop para "remover" a pessoa da lista de quem pegou o livro emprestado
                            livros[i].emprestaram[k] = livros[i].emprestaram[k + 1];
                        }
                                
                        (livros[i].qnt_emprestaram)--;

                        // Opcional: Zera o último elemento (não necessário, mas ajuda a manter a integridade)
                        livros[i].emprestaram[livros[i].qnt_emprestaram].nomeCliente[0] = '\0';
                        livros[i].emprestaram[livros[i].qnt_emprestaram].CPF[0] = '\0';
                        livros[i].quantidade_disponivel++;
                        
                        cout << "Livro devolvido com sucesso!" << endl;
                        break; // Sai do "for" que verifica a lista dos nomes porque o "nome" já foi encontrado e "limpo"
                    }
                }
                break; // Sai do "for" que verifica a lista dos livros. Assim que um livro é encontrado e o nome é limpo, não precisa ver os outros livros.
            }
        }
        
        if (!existe) {
            cout << "Livro não encontrado. Tente novamente..." << endl;
            continue;
        }

        if (!pessoa_encontrada) {
            cout << "Pessoa não encontrada. Tente novamente..." << endl;
            continue;
        }

        int opcao2;
        cout << "Deseja devolver outro livro? \n[1-Sim | 2-Não]: ";
        cin >> opcao2;

        if (opcao2 == 1) {
            continue; // volta para o inicio do While
        } else {
            limparTela();
            return; // volta para o Menu
        }
    }
}


void remocaoLivros(struct livro livros[], int *sz) {
    int opcao, id_requisitado;
    bool validacao = true;

    while (validacao) {
        limparTela();
        cout << "\n\t===== REMOVER LIVROS =====" << endl;

        cout << "\nDeseja consultar os livros cadastrados? \n[1-Sim | 2-Não]: " << endl;
        cin >> opcao;

        // Verifica a entrada do usuário
        if (opcao != 1 && opcao != 2) {
            cout << "Opção inválida! Por favor, digite [1] ou [2]." << endl;
            continue;  // Volta para o início do loop
        } else if (opcao == 1) {
            printLivrosVet(livros, *sz);
        }

        cout << "\nDigite o id para remover o livro: " << endl;
        cin >> id_requisitado;

        bool livroRemovido = false; // Flag para verificar se o livro foi removido
        
        for (int i = 0; i < *sz; i++) { // Corrigido de <= para <
            if (id_requisitado == livros[i].id) {
                for (int j = i; j < *sz - 1; j++) { // Corrigido de <= para <
                    livros[j] = livros[j + 1];
                }
                
                livroRemovido = true; // Marcar que um livro foi removido
                
                (*sz)--; // Reduzir o tamanho do vetor
                
                cout << "Livro Removido!" << endl;
                break; // Sair do loop de remoção
            }
        }

        if (!livroRemovido) {
            cout << "Livro não encontrado!" << endl;
        }

        validacao = false; // Se você quer sair após a remoção, mantenha isso. Se não, remova esta linha.
    
    
        int opcao2;
        cout << "Deseja remover outro livro? \n[1-Sim | 2-Não]: ";
        cin >> opcao2;

        if (opcao2 == 1) {
            continue; // volta para o inicio do While
        } else {
            limparTela();
            return; // volta para o Menu
        }
    }   
}

int main () {
    struct livro vetLivros[100];
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
        cout << "6. Sair do programa" << endl << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cin.ignore();
                cadastrarLivros (vetLivros, &qnt_livros);    
                break;
            case 2:
                cin.ignore();
                consultaLivros(vetLivros, qnt_livros); 
                break;
            case 3:
                emprestimoLivros(vetLivros, qnt_livros);                
                break;
            case 4:
                devolucaoLivros(vetLivros, qnt_livros);
                break;
            case 5:
                limparTela();
                remocaoLivros(vetLivros, &qnt_livros);
                break;
            case 6:
                cout << "Até logo...";
                return 0;
            default:
                cout << "Opção inválida!";
                break;
        }

        cout << endl;
    
    } while (qnt_livros != 6);

    return 0;
}
