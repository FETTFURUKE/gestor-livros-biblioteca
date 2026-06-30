// Prototipo das Funções Listar Usuario
void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total);

int main(){

    // Função Listar Usuario
    void listarUsuario(int codigo[], char nome[][50], char telefone[][50], char email[], int total){

        if (total == 0){
            printf("--- Nenhum livro cadatrado ---\n");

            for (int i = 0; i < total; i++){
                printf("Código: %d\n", codigo[i]);
                printf("Nome: %s\n", nome[i]);
                printf("Telefone: %s\n", telefone[i]);
                printf("Email: %s", email[i]);
                printf("------------------------------");
            }
        }
    }

    return ;
}