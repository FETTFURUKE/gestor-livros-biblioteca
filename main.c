#include <stdio.h>
#include<windows.h>
#include <stdbool.h>


#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

// Prototipo das Funções Listar
void menu_usuario();
void menu_livro();
void listarUsuario(int codigo[], char nome[][50], char telefone[][9], char email[20], int total);
void excluirLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void excluirUsuario(int codigo[], char nome[][50], char telefone[][9], char email[20], int total);


void pausar()
{
    system("pause");
}

void menu_principal(){
    printf("=============================\n");
    printf("--- Gerenciador de Biblioteca ---\n");
    printf("1 - Gerenciar Livros\n");
    printf("2 - Gerenciar Usuários\n");
    printf("3 - Empréstimos\n");
    printf("4 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main (){
    SetConsoleOutputCP(CP_UTF8);

    
    int opcao;

    bool sistemaAtivo = true;

    while (sistemaAtivo)
    {
        menu_principal();

        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_livro();
            break;

        case 2:
            menu_usuario();
            break;

        case 3:
        
            break;

        case 4:
        
            break;

        case 0:
            printf("\n ===== PROGRAMA ENCERRADO ===== \n");
            sistemaAtivo = false;
            break;

        default:
            printf("\nOpção inválida!\n");
        }

        if (sistemaAtivo)
        {
            pausar();
        }
    }
    return 0;
}

    // Função Listar Livro
    void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total){

        if (total == 0){
            printf("--- Nenhum livro cadastrado! ---\n");
         }

    printf("--- Lista de livros cadastrados ---");
        
        for (int i = 0; i < total; i++){
            printf("Código: %d\n", codigo[i]);
            printf("Titulo: %s\n", titulo[i]);
            printf("Autor: %s\n", autor[i]);
            printf("Categoria: %d", categoria[i]);
            printf("Ano: %d", ano[i]);
            printf("Quantidade: %d", quantidade[i]);
            printf("Quantidade Disponivel: %d", quant_disponivel[i]);
            printf("------------------------------");
        }
}

    // Função Listar Usuario
    void listarUsuario(int codigo[], char nome[][50], char telefone[][9], char email[20], int total){

        if (total == 0){
            printf("--- Nenhum usuário cadatrado ---\n");
        

    printf("--- Lista de usuários cadastrados ---");

        for (int i = 0; i < total; i++){
            printf("Código: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Telefone: %s\n", telefone[i]);
            printf("Email: %c", email[i]);
            printf("------------------------------");
        }
    }
}

void menu_livro(){
    printf("=============================\n");
    printf("--- Gerenciamento de Livros ---\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Bruscar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opção: ");

    int opcao, codigo, ano, quantidade, quant_disponivel;
    char titulo, autor, categoria

        bool sistemaAtivo = true;

    while (sistemaAtivo)
    {
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            
            break;

        case 2:
            listarLivro(codigo, titulo, autor, categoria, ano, quantidade, quant_disponivel);
            break;

        case 3:
        
            break;

        case 4:
        
            break;

        case 0:
            menu_principal();
            break;

        default:
            printf("\nOpção inválida!\n");
        }

        if (sistemaAtivo)
        {
            pausar();
        }
    }
    return 0;
}

void menu_usuario(){
    printf("=============================\n");
    printf("--- Gerenciamento de Usuarios ---\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Bruscar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opção: ");

        int opcao;

        bool sistemaAtivo = true;

    while (sistemaAtivo)
    {
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            
            break;

        case 2:
            listarUsuario(codigo, nome, telefone, email);
            break;

        case 3:
        
            break;

        case 4:
        
            break;

        case 0:
            menu_principal();
            break;

        default:
            printf("\nOpção inválida!\n");
        }

        if (sistemaAtivo)
        {
            pausar();
        }
    }
    return 0;
}
