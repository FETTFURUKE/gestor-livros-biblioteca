#include <stdio.h>
#include<windows.h>






#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

int quantidade, ano,codigo,quantidadedisponivel;
char titulo, autor, categoria;

typedef struct{

int quantidade, ano,codigo,quantidadedisponivel;
char titulo, autor, categoria;


}livros[MAX_LIVROS];



void cadastroLivro(){
printf(" digite o codigo do livro: ");
scanf("%d", &codigo);
printf("Digite o titulo do livro: ");
scanf("%s", titulo);
printf("Digite o nome do autor: ");
scanf("%s", autor);
printf("Digite a categoria do livro: ");
scanf("%s", categoria);
printf("Digite o ano do livro: ");
scanf("%d", &ano);
printf("Digite a quantidade de livros: ");
scanf("%d", &quantidade);

printf("%d", codigo );
printf("%s", titulo );
printf("%s", autor);
}


// Prototipo das Funções Listar
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);

void menu(){
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
   cadastroLivro();
  

    

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
    void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total){

        if (total == 0){
            printf("--- Nenhum usuário cadatrado ---\n");
      

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

