#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    int categoria;
    int ano;
    int quantidade;
    int quant_disponivel;
} livro;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[15];
    char email[50];
} usuario;

livro acervo[MAX_LIVROS];
int total_livros = 0;
usuario usuarios[MAX_USUARIOS];
int total_usuarios = 0;

// 3. Protótipos de Funções
void menu_livro();
void menu_usuario();
void listarLivro();
void excluirLivro();
void buscarLivro();
void listarUsuario();
void excluirUsuario();
void buscarUsuario();

void pausar() {
    system("pause");
}

void menu_principal() {
    printf("\n=============================\n");
    printf("--- Gerenciador de Biblioteca ---\n");
    printf("1 - Gerenciar Livros\n");
    printf("2 - Gerenciar Usuários\n");
    printf("3 - Empréstimos\n");
    printf("4 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    
    int opcao;
    bool sistemaAtivo = true;

while (sistemaAtivo) {
        menu_principal();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_livro();
                break;
            case 2:
                menu_usuario();
                break;
            case 3:
                printf("emprestimo\n");
                pausar();
                break;
            case 4:
                printf("relatorio\n");
                pausar();
                break;
            case 0:
                printf("\n===== PROGRAMA ENCERRADO =====\n");
                sistemaAtivo = false;
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }
    }
    return 0;
}

void menu_livro() {
    int opcao;
    bool menuAtivo = true;

    while (menuAtivo) {
        printf("\n=============================\n");
        printf("--- Gerenciamento de Livros ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("cadastro\n");
                break;
            case 2:
                listarLivro();
                break;
            case 3:
                printf("buscar\n");
                break;
            case 4:
                printf("alterar\n");
                break;
            case 5:
                excluirLivro();
                break;
            case 0:
                menuAtivo = false;
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    }
}

void menu_usuario() {
    int opcao;
    bool menuAtivo = true;

    while (menuAtivo) {
        printf("\n=============================\n");
        printf("--- Gerenciamento de Usuarios ---\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("cadastro\n");
                break;
            case 2:
                listarUsuario();
                break;
            case 3:
                printf("buscar\n");
                break;
            case 4:
                printf("alterar\n");
                break;
            case 5:
                excluirUsuario();
                break;
            case 0:
                menuAtivo = false;
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    }
}

void listarLivro() {
    
   if (total_livros == 0) {
        printf("\n--- Nenhum livro cadastrado! ---\n");
        return;
    }

    printf("\n--- Lista de livros cadastrados ---\n");
    for (int i = 0; i < total_livros; i++) {
        printf("Código: %d\n", acervo[i].codigo);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Categoria: %d\n", acervo[i].categoria);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Qtd Total: %d | Qtd Disponível: %d\n", acervo[i].quantidade, acervo[i].quant_disponivel);
        printf("------------------------------\n");
    }
}

void excluirLivro() {
    if (total_livros == 0) {
        printf("\nNão há livros para excluir.\n");
        return;
    }

    int codigoExcluir;
    printf("\nDigite o código do livro que deseja excluir: ");
    scanf("%d", &codigoExcluir);

    bool encontrado = false;
    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].codigo == codigoExcluir) {
            encontrado = true;
            // Desloca os livros seguintes para preencher o espaço
            for (int j = i; j < total_livros - 1; j++) {
                acervo[j] = acervo[j + 1];
            }
            total_livros--;
            printf("Livro excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Livro não encontrado!\n");
    }
}

void listarUsuario() {
    if (total_usuarios == 0) {
        printf("\n--- Nenhum usuário cadastrado! ---\n");
        return;
    }

    printf("\n--- Lista de usuários cadastrados ---\n");
    for (int i = 0; i < total_usuarios; i++) {
        printf("Código: %d\n", usuarios[i].codigo);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Telefone: %s\n", usuarios[i].telefone);
        printf("Email: %s\n", usuarios[i].email);
        printf("------------------------------\n");
    }
}

void excluirUsuario() {
    if (total_usuarios == 0) {
        printf("\nNão há usuários para excluir.\n");
        return;
    }

    int codigoExcluir;
    printf("\nDigite o código do usuário que deseja excluir: ");
    scanf("%d", &codigoExcluir);

    bool encontrado = false;
    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].codigo == codigoExcluir) {
            encontrado = true;
            for (int j = i; j < total_usuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            total_usuarios--;
            printf("Usuário excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado!\n");
    }

         // FUNÇÃO BUSCAR LIVRO //
void buscarLivro(int codigo[],
         char titulo[][50],
         char autor[][50],
         int categoria[],
         int ano[],
         int quantidade[],
         int quant_disponivel[],
         int total) {

    char nomeBusca[50];
    int encontrado = 0;

    printf("\nDigite o Nome do livro para Buscar: ");
    fgets(nomeBusca, 50, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
    for (int i = 0; i < total; i++) {
        if (strcmp(titulo[i], nomeBusca) == 0) {
            printf("\n ----- LIVRO ENCONTRADO ----- \n");
            printf("Código: %d\n", codigo[i]);
            printf("Titulo: %s\n", titulo[i]);
            printf("Autor: %s\n", autor[i]);
            printf("Categoria: %d\n", categoria[i]);
            printf("Ano: %d\n", ano[i]);
            printf("Quantidade: %d\n", quantidade[i]);
            printf("Quantidade Disponivel: %d\n", quant_disponivel[i]);
            printf("------------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\n ----- PRODUTO NAO ENCONTRADO ----- \n");
    }
}
//FUNÇÃO BUSCAR USUARIO//
void buscarUsuario(int codigo[],
                  char nome[][50],
                  char telefone[][50],
                  char email[][50],
                  int total) {
    char nomeBusca[50];
    int encontrado = 0;

    printf("\nDigite o Nome do usuário para Buscar: ");
    fgets(nomeBusca, 50, stdin);

    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
    for (int i = 0; i < total; i++) {
        if (strcmp(nome[i], nomeBusca) == 0) {
            printf("\n ----- USUARIO ENCONTRADO ----- \n");
            printf("Código: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Telefone: %s\n", telefone[i]);
            printf("Email: %s\n", email[i]);
            printf("------------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\n ----- USUARIO NAO ENCONTRADO ----- \n");
    }
}
}

