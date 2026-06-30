#include <stdio.h>
#include<windows.h>


#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

// Prototipo das Funções Listar
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);

int main (){
    SetConsoleOutputCP(CP_UTF8);

    int i, j, 

    do
    {
        /* code */
    } while (opcao != 0);
    

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