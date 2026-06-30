#include <stdio.h>

// Prototipo das Funções Listar
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);

int main (){

return 0;

}

    // Função Listar Livro
    void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total)
    {

        if (total == 0){
            printf("--- Nenhum livro cadatrado ---\n");

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
        
    }




    // Função Listar Usuario
    void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total){

        if (total == 0){
            printf("--- Nenhum livro cadatrado ---\n");

            for (int i = 0; i < total; i++){
                printf("Código: %d\n", codigo[i]);
                printf("Nome: %s\n", nome[i]);
                printf("Telefone: %s\n", telefone[i]);
                printf("Email: %c", email[i]);
                printf("------------------------------");
            }
        }
}