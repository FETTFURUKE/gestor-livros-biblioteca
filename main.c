#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200



// Prototipo das Funções Listar
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[][50], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void BuscarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);
void BuscarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[][50], int total);
int main (){

return 0;

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
    // Função Listar Livro
    void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total)
    {
        if (total == 0) {
            printf("--- Nenhum livro cadastrado ---\n");
        } else {
            for (int i = 0; i < total; i++) {
                printf("Código: %d\n", codigo[i]);
                printf("Titulo: %s\n", titulo[i]);
                printf("Autor: %s\n", autor[i]);
                printf("Categoria: %d\n", categoria[i]);
                printf("Ano: %d\n", ano[i]);
                printf("Quantidade: %d\n", quantidade[i]);
                printf("Quantidade Disponivel: %d\n", quant_disponivel[i]);
                printf("------------------------------\n");
            }
        }
    }

    // Função Listar Usuario
    void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[][50], int total)
    {
        if (total == 0) {
            printf("--- Nenhum usuário cadastrado ---\n");
        } else {
            for (int i = 0; i < total; i++) {
                printf("Código: %d\n", codigo[i]);
                printf("Nome: %s\n", nome[i]);
                printf("Telefone: %s\n", telefone[i]);
                printf("Email: %s\n", email[i]);
                printf("------------------------------\n");
            }
        }
    }
