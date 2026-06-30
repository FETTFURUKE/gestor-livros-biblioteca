// Prototipo das Funções Livro
void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total);

int main(){

    // Função Listar Livro
    void listarLivro(int codigo[], char titulo[][50], char autor[][50], int categoria[], int ano[], int quantidade[], int quant_disponivel[], int total){

        if (total == 0){
            printf("--- Nenhum livro cadatrado ---\n");

            for (int i = 0; i < total; i++){
                printf("Código: %d\n", codigo[i]);
                printf("Titulo: %s\n", titulo[i]);
                printf("Autor: %s\n", autor[i]);
                printf("Categoria: %d", cate[i]);
                printf("Ano: %d", ano[i]);
                printf("Quantidade: %d", quantidade[i]);
                printf("Quantidade Disponivel: %d", quant_disponivel[i]);
                printf("------------------------------");
            }
        }
        }

    return ;
}