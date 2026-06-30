#include <stdio.h>
#include<windows.h>
#include <stdbool.h>


#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

// Prototipo das Funções Listar
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);
void excluirLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void excluirUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);

void pausar()
{
    system("pause");
}

void menu_principal(){
    printf("=============================\n");
    printf("--- Gerenciador de Biblioteca ---\n");
    printf("1 - Gerenciar Livros\n");
    prinft("2 - Gerenciar Usuários\n");
    printf("3 - Empréstimos\n");
    printf("4 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void menu_livro(){
    printf("=============================\n");
    printf("--- Gerenciamento de Livros ---\n");
    printf("1 - Cadastrar\n");
    prinft("2 - Listar\n");
    printf("3 - Bruscar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opção: ");
}

void menu_usuario(){
    printf("=============================\n");
    printf("--- Gerenciamento de Usuarios ---\n");
    printf("1 - Cadastrar\n");
    prinft("2 - Listar\n");
    printf("3 - Bruscar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opção: ");
}

int main (){
    SetConsoleOutputCP(CP_UTF8);

    int total = 0;
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
            return 0;
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
    void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total){

        if (total == 0){
            printf("--- Nenhum usuário cadatrado ---\n");
            return 0;

        }

    printf("--- Lista de usuários cadastrados ---");

        for (int i = 0; i < total; i++){
            printf("Código: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Telefone: %s\n", telefone[i]);
            printf("Email: %c", email[i]);
            printf("------------------------------");
        }
}

    // Função excluir livro
    int excluirLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total){
    char nomeBusca[50];
    int encontrado = 0;

    getchar();

    printf("\nDigite o nome do Livro para remover: ");
    fgets(nomeBusca, 50, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    converterMaiusculo(nomeBusca);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(titulo[i], nomeBusca) == 0)
        {
            // Move os produtos seguintes para preencher a lacuna
            for (int j = i; j < total - 1; j++)
            {
                strcpy(codigo[j], codigo[j + 1]);
                titulo[j] = titulo[j + 1];
                autor[j] = autor[j + 1];
                categoria[j] = categoria [j + 1];
                ano[j] = ano [j + 1];
                quantidade[j] = quantidade [j + 1];
                quant_disponivel[j] = quant_disponivel [j + 1];
            }

            // Limpa o último produto
            codigo[total - 1][0] = '\0';
            titulo[total - 1] = 0;
            autor[total - 1] = 0;
            categoria[total - 1] = 0;
            ano[total - 1] = 0;
            quantidade[total - 1] = 0;
            quant_disponivel[total - 1] = 0;

            printf("\n ===== PRODUTO REMOVIDO COM SUCESSO! ===== \n");
            return total - 1; // Decrementa o total de produtos
        }
    }

    if (!encontrado)
    {
        printf("\n ===== PRODUTO NÃO ENCONTRADO! ===== \n");
        return total;
    }

    return total;
}