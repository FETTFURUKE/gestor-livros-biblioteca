#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_EMPRESTIMOS 200

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    char categoria[20];
    int ano;
    int quant;
    int quant_disponivel;
    int vezes_emprestado;
} livro;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
    char email[50];
} usuario;

typedef struct {
    int codigo_usuario;
    int codigo_livro;
    bool ativo; 
} emprestimo;

livro acervo[MAX_LIVROS];
int total_livros = 0;
int proximo_codigo_livro = 1;

usuario usuarios[MAX_USUARIOS];
int total_usuarios = 0;
int proximo_codigo_usuario = 1;

emprestimo emprestimos[MAX_EMPRESTIMOS];
int total_emprestimos = 0;

void limparEnter(char texto[]);
void pausar();
void menu_principal();
void menu_livro();
void menu_usuario();
void menu_emprestimo();
void menu_relatorio();

void cadastrarLivro();
void listarLivro();
void buscarLivro();
void alterarLivro();
void excluirLivro();

void cadastrarUsuario();
void listarUsuario();
void buscarUsuario();
void alterarUsuario();
void excluirUsuario();

void realizarEmprestimo();
void realizarDevolucao();

void relatorioTodosLivros();
void relatorioLivrosDisponiveis();
void relatorioLivrosEmprestados();
void relatorioTodosUsuarios();
void relatorioUsuariosComEmprestimo();
void relatorioEstatisticas();

void limparEnter(char texto[]){
    texto[strcspn(texto, "\n")] = '\0';
}

void pausar() {
    system("pause");
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
                menu_emprestimo();
                break;
            case 4:
                menu_relatorio();
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

void menu_principal() {
    printf("\n============ BIBLIOTECA ============\n");
    printf("1 - Gerenciar Livros\n");
    printf("2 - Gerenciar Usuários\n");
    printf("3 - Empréstimos\n");
    printf("4 - Relatórios\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
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
            case 1: cadastrarLivro(); break;
            case 2: listarLivro(); break;
            case 3: buscarLivro(); break;
            case 4: alterarLivro(); break;
            case 5: excluirLivro(); break;
            case 0: menuAtivo = false; break;
            default: printf("\nOpção inválida!\n"); pausar();
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
            case 1: cadastrarUsuario(); break;
            case 2: listarUsuario(); break;
            case 3: buscarUsuario(); break;
            case 4: alterarUsuario(); break;
            case 5: excluirUsuario(); break;
            case 0: menuAtivo = false; break;
            default: printf("\nOpção inválida!\n"); pausar();
        }
    }
}

void menu_emprestimo() {
    int opcao;
    bool menuAtivo = true;

    while (menuAtivo) {
        printf("\n=============================\n");
        printf("--- Gerenciamento de Empréstimos ---\n");
        printf("1 - Realizar Empréstimo\n");
        printf("2 - Realizar Devolução\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: realizarEmprestimo(); break;
            case 2: realizarDevolucao(); break;
            case 0: menuAtivo = false; break;
            default: printf("\nOpção inválida!\n"); pausar();
        }
    }
}

void menu_relatorio() {
    int opcao;
    bool menuAtivo = true;

    while (menuAtivo) {
        printf("\n=============================\n");
        printf("--- Relatórios do Sistema ---\n");
        printf("1 - Todos os livros\n");
        printf("2 - Livros disponíveis\n");
        printf("3 - Livros emprestados\n");
        printf("4 - Usuários cadastrados\n");
        printf("5 - Usuários com empréstimos ativos\n");
        printf("6 - Estatísticas gerais (Qtd e Mais Emprestado)\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: relatorioTodosLivros(); break;
            case 2: relatorioLivrosDisponiveis(); break;
            case 3: relatorioLivrosEmprestados(); break;
            case 4: relatorioTodosUsuarios(); break;
            case 5: relatorioUsuariosComEmprestimo(); break;
            case 6: relatorioEstatisticas(); break;
            case 0: menuAtivo = false; break;
            default: printf("\nOpção inválida!\n"); pausar();
        }
    }
}

void cadastrarLivro(){
    if (total_livros >= MAX_LIVROS){
        printf("\nLimite de cadastro de livros atingido!\n");
        pausar();
        return;
    }

    int i = total_livros;
    acervo[i].codigo = proximo_codigo_livro++; 
    acervo[i].vezes_emprestado = 0; 

    getchar(); 
    printf("\n--- CADASTRO DE LIVROS ---\n");
        
    do {
        printf("\nTítulo do Livro (Obrigatório): ");
        fgets(acervo[i].titulo, 50, stdin);
        limparEnter(acervo[i].titulo);
        
        if (strlen(acervo[i].titulo) == 0) {
            printf("Erro: O título não pode ficar em branco!\n");
        }
    } while (strlen(acervo[i].titulo) == 0);

    printf("\nAutor do Livro: ");
    fgets(acervo[i].autor, 50, stdin);
    limparEnter(acervo[i].autor);

    printf("\nCategoria: ");
    fgets(acervo[i].categoria, 20, stdin);
    limparEnter(acervo[i].categoria);

    printf("\nAno de Publicação: ");
    scanf("%d", &acervo[i].ano);

    do {
        printf("\nQuantidade total adquirida: ");
        scanf("%d", &acervo[i].quant);
        
        if (acervo[i].quant < 0) {
            printf("Erro: A quantidade não pode ser negativa!\n");
        }
    } while (acervo[i].quant < 0);

    acervo[i].quant_disponivel = acervo[i].quant; 

    total_livros++;
    printf("\nLivro cadastrado com sucesso! (Código: %d)\n", acervo[i].codigo);
    pausar();
}

void listarLivro() {
    relatorioTodosLivros(); 
}

void buscarLivro(){
    char tituloBusca[50];
    int encontrado = 0;

    getchar();
    printf("\nDigite o título do livro que deseja buscar: ");
    fgets(tituloBusca, 50, stdin);
    limparEnter(tituloBusca);

    for (int i = 0; i < total_livros; i++) {
        if (strstr(acervo[i].titulo, tituloBusca) != NULL) {
            printf("\nLivro encontrado!\n");
            printf("Código: %d | Título: %s | Autor: %s\n", acervo[i].codigo, acervo[i].titulo, acervo[i].autor);
            printf("Qtd Total: %d | Qtd Disponível: %d\n", acervo[i].quant, acervo[i].quant_disponivel);
            encontrado = 1;
        }
    }

    if (encontrado == 0) printf("\nLivro não encontrado!\n");
    pausar();
}

void alterarLivro(){
    int codigoAlterar;
    printf("\nDigite o código do livro que deseja alterar: ");
    scanf("%d", &codigoAlterar);
    bool encontrado = false;

    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].codigo == codigoAlterar) {
            encontrado = true;
            getchar();
            
            int qtdEmprestadaAtual = acervo[i].quant - acervo[i].quant_disponivel;

            printf("\n--- Alteração de Livro (Código %d) ---\n", acervo[i].codigo);

            printf("Novo Título do Livro: ");
            fgets(acervo[i].titulo, 50, stdin);
            limparEnter(acervo[i].titulo);

            printf("Novo Autor do Livro: ");
            fgets(acervo[i].autor, 50, stdin); 
            limparEnter(acervo[i].autor);

            printf("Nova Categoria: ");
            fgets(acervo[i].categoria, 20, stdin);
            limparEnter(acervo[i].categoria);

            printf("Novo Ano de Publicação: ");
            scanf("%d", &acervo[i].ano);

            int novaQuant;
            do {
                printf("Nova Quantidade total adquirida (Mínimo %d devido a empréstimos ativos): ", qtdEmprestadaAtual);
                scanf("%d", &novaQuant);
                if(novaQuant < qtdEmprestadaAtual) {
                    printf("Erro: Não pode ser menor que a quantidade de livros já emprestados no momento.\n");
                }
            } while (novaQuant < qtdEmprestadaAtual);
            
            acervo[i].quant = novaQuant;
            acervo[i].quant_disponivel = acervo[i].quant - qtdEmprestadaAtual;

            printf("\nLivro alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) printf("\nLivro não encontrado!\n");
    pausar();
}

void excluirLivro() {
    if (total_livros == 0) {
        printf("\nNão há livros para excluir.\n");
        pausar(); return;
    }

    int codigoExcluir;
    printf("\nDigite o código do livro que deseja excluir: ");
    scanf("%d", &codigoExcluir);

    bool encontrado = false;
    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].codigo == codigoExcluir) {
            encontrado = true;
            
            if (acervo[i].quant_disponivel < acervo[i].quant) {
                printf("\nErro: Este livro possui exemplares emprestados e não pode ser excluído no momento!\n");
                pausar(); return;
            }

            for (int j = i; j < total_livros - 1; j++) {
                acervo[j] = acervo[j + 1];
            }
            total_livros--;
            printf("\nLivro excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) printf("\nLivro não encontrado!\n");
    pausar();
}

void cadastrarUsuario(){
    if (total_usuarios >= MAX_USUARIOS){
        printf("\nLimite de cadastro de usuários atingido!\n");
        pausar(); return;
    }

    int i = total_usuarios;
    usuarios[i].codigo = proximo_codigo_usuario++;

    getchar();
    printf("\n--- CADASTRO DE USUÁRIO ---\n");
    
    do {
        printf("\nNome do usuário (Obrigatório): ");
        fgets(usuarios[i].nome, 50, stdin);
        limparEnter(usuarios[i].nome);
        if (strlen(usuarios[i].nome) == 0) {
            printf("Erro: O nome não pode ficar em branco!\n");
        }
    } while (strlen(usuarios[i].nome) == 0);

    printf("Telefone: ");
    fgets(usuarios[i].telefone, 20, stdin);
    limparEnter(usuarios[i].telefone);

    printf("Email: ");
    fgets(usuarios[i].email, 50, stdin);
    limparEnter(usuarios[i].email);

    total_usuarios++;
    printf("\nUsuário cadastrado com sucesso! (Código: %d)\n", usuarios[i].codigo);
    pausar();
}

void listarUsuario() {
    relatorioTodosUsuarios(); 
}

void buscarUsuario(){
    char nomeBusca[50];
    int encontrado = 0;

    getchar();
    printf("\nDigite o nome do usuário que deseja buscar: ");
    fgets(nomeBusca, 50, stdin);
    limparEnter(nomeBusca);

    for (int i = 0; i < total_usuarios; i++) {
        if (strstr(usuarios[i].nome, nomeBusca) != NULL) {
            printf("\nUsuário encontrado!\n");
            printf("Código: %d | Nome: %s | Telefone: %s\n", usuarios[i].codigo, usuarios[i].nome, usuarios[i].telefone);
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\nUsuário não encontrado!\n");
    pausar();
}

void alterarUsuario(){
    int codigoAlterar;
    printf("\nDigite o código do usuário que deseja alterar: ");
    scanf("%d", &codigoAlterar);
    bool encontrado = false;

    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].codigo == codigoAlterar) {
            encontrado = true;
            getchar();
            printf("\n--- Alteração de Usuário (Código %d) ---\n", usuarios[i].codigo);

            printf("Novo Nome do usuário: ");
            fgets(usuarios[i].nome, 50, stdin);
            limparEnter(usuarios[i].nome);

            printf("Novo Telefone: ");
            fgets(usuarios[i].telefone, 20, stdin);
            limparEnter(usuarios[i].telefone);

            printf("Novo Email: ");
            fgets(usuarios[i].email, 50, stdin);
            limparEnter(usuarios[i].email);

            printf("\nUsuário alterado com sucesso!\n");
            break;
        }
    }
    if (!encontrado) printf("\nUsuário não encontrado!\n");
    pausar();
}

void excluirUsuario() {
    if (total_usuarios == 0) {
        printf("\nNão há usuários para excluir.\n");
        pausar(); return;
    }

    int codigoExcluir;
    printf("\nDigite o código do usuário que deseja excluir: ");
    scanf("%d", &codigoExcluir);

    bool encontrado = false;
    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].codigo == codigoExcluir) {
            encontrado = true;
            
            for(int k=0; k < total_emprestimos; k++){
                if(emprestimos[k].codigo_usuario == codigoExcluir && emprestimos[k].ativo){
                    printf("\nErro: Este usuário possui empréstimos pendentes e não pode ser excluído!\n");
                    pausar(); return;
                }
            }

            for (int j = i; j < total_usuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            total_usuarios--;
            printf("\nUsuário excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) printf("\nUsuário não encontrado!\n");
    pausar();
}

void realizarEmprestimo() {
    if (total_emprestimos >= MAX_EMPRESTIMOS) {
        printf("\nLimite máximo de registros de empréstimos atingido!\n");
        pausar(); return;
    }

    int codUser, codLivro;
    int idxUser = -1, idxLivro = -1;

    printf("\n--- NOVO EMPRÉSTIMO ---\n");
    printf("Digite o código do Usuário: ");
    scanf("%d", &codUser);
    printf("Digite o código do Livro: ");
    scanf("%d", &codLivro);

    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].codigo == codUser) { idxUser = i; break; }
    }
    if (idxUser == -1) {
        printf("\nErro: Usuário não encontrado no sistema.\n");
        pausar(); return;
    }

    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].codigo == codLivro) { idxLivro = i; break; }
    }
    if (idxLivro == -1) {
        printf("\nErro: Livro não encontrado no sistema.\n");
        pausar(); return;
    }

    for (int i = 0; i < total_emprestimos; i++) {
        if (emprestimos[i].codigo_usuario == codUser && 
            emprestimos[i].codigo_livro == codLivro && 
            emprestimos[i].ativo == true) {
            printf("\nErro: O usuário %s já possui um exemplar de '%s' emprestado!\n", usuarios[idxUser].nome, acervo[idxLivro].titulo);
            pausar(); return;
        }
    }

    if (acervo[idxLivro].quant_disponivel <= 0) {
        printf("\nErro: Não há exemplares disponíveis do livro '%s' no momento.\n", acervo[idxLivro].titulo);
        pausar(); return;
    }

    emprestimos[total_emprestimos].codigo_usuario = codUser;
    emprestimos[total_emprestimos].codigo_livro = codLivro;
    emprestimos[total_emprestimos].ativo = true;
    total_emprestimos++;

    acervo[idxLivro].quant_disponivel--;
    acervo[idxLivro].vezes_emprestado++; 

    printf("\nEmpréstimo registrado com sucesso!\n");
    printf("Livro: %s\nUsuário: %s\n", acervo[idxLivro].titulo, usuarios[idxUser].nome);
    pausar();
}

void realizarDevolucao() {
    int codUser, codLivro;

    printf("\n--- DEVOLUÇÃO DE LIVRO ---\n");
    printf("Digite o código do Usuário: ");
    scanf("%d", &codUser);
    printf("Digite o código do Livro: ");
    scanf("%d", &codLivro);

    bool encontrado = false;

    for (int i = 0; i < total_emprestimos; i++) {
        if (emprestimos[i].codigo_usuario == codUser && 
            emprestimos[i].codigo_livro == codLivro && 
            emprestimos[i].ativo == true) {
            
            emprestimos[i].ativo = false; 
            encontrado = true;

            for (int j = 0; j < total_livros; j++) {
                if (acervo[j].codigo == codLivro) {
                    acervo[j].quant_disponivel++;
                    printf("\nDevolução registrada com sucesso!\nLivro '%s' retornou ao acervo.\n", acervo[j].titulo);
                    break;
                }
            }
            break;
        }
    }

    if (!encontrado) {
        printf("\nErro: Nenhum empréstimo ativo encontrado para este Usuário e Livro.\n");
    }
    pausar();
}

void relatorioTodosLivros() {
    if (total_livros == 0) {
        printf("\n--- Nenhum livro cadastrado! ---\n");
        pausar(); return;
    }
    printf("\n--- RELATÓRIO: TODOS OS LIVROS ---\n");
    for (int i = 0; i < total_livros; i++) {
        printf("[%d] %s (Autor: %s) - Total: %d | Disponível: %d\n", 
            acervo[i].codigo, acervo[i].titulo, acervo[i].autor, acervo[i].quant, acervo[i].quant_disponivel);
    }
    pausar();
}

void relatorioLivrosDisponiveis() {
    bool achou = false;
    printf("\n--- RELATÓRIO: LIVROS DISPONÍVEIS ---\n");
    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].quant_disponivel > 0) {
            printf("[%d] %s - Disponíveis: %d\n", acervo[i].codigo, acervo[i].titulo, acervo[i].quant_disponivel);
            achou = true;
        }
    }
    if (!achou) printf("Nenhum livro disponível no momento.\n");
    pausar();
}

void relatorioLivrosEmprestados() {
    bool achou = false;
    printf("\n--- RELATÓRIO: LIVROS EMPRESTADOS (FORA DO ACERVO) ---\n");
    for (int i = 0; i < total_livros; i++) {
        if (acervo[i].quant > acervo[i].quant_disponivel) {
            int emprestados = acervo[i].quant - acervo[i].quant_disponivel;
            printf("[%d] %s - Emprestados: %d\n", acervo[i].codigo, acervo[i].titulo, emprestados);
            achou = true;
        }
    }
    if (!achou) printf("Nenhum livro emprestado no momento.\n");
    pausar();
}

void relatorioTodosUsuarios() {
    if (total_usuarios == 0) {
        printf("\n--- Nenhum usuário cadastrado! ---\n");
        pausar(); return;
    }
    printf("\n--- RELATÓRIO: USUÁRIOS CADASTRADOS ---\n");
    for (int i = 0; i < total_usuarios; i++) {
        printf("[%d] %s | Tel: %s | Email: %s\n", 
            usuarios[i].codigo, usuarios[i].nome, usuarios[i].telefone, usuarios[i].email);
    }
    pausar();
}

void relatorioUsuariosComEmprestimo() {
    bool achou = false;
    printf("\n--- RELATÓRIO: USUÁRIOS COM EMPRÉSTIMOS ATIVOS ---\n");
    
    for (int i = 0; i < total_usuarios; i++) {
        int emprestimosDesteUser = 0;
        for (int j = 0; j < total_emprestimos; j++) {
            if (emprestimos[j].codigo_usuario == usuarios[i].codigo && emprestimos[j].ativo) {
                emprestimosDesteUser++;
            }
        }
        
        if (emprestimosDesteUser > 0) {
            printf("[%d] %s - Empréstimos ativos: %d\n", usuarios[i].codigo, usuarios[i].nome, emprestimosDesteUser);
            achou = true;
        }
    }
    if (!achou) printf("Nenhum usuário com pendências no momento.\n");
    pausar();
}

void relatorioEstatisticas() {
    if (total_livros == 0) {
        printf("\nAcervo vazio para estatísticas.\n");
        pausar(); return;
    }

    int soma_total = 0;
    int indexMaisEmprestado = 0;

    for (int i = 0; i < total_livros; i++) {
        soma_total += acervo[i].quant;
        if (acervo[i].vezes_emprestado > acervo[indexMaisEmprestado].vezes_emprestado) {
            indexMaisEmprestado = i;
        }
    }

    printf("\n--- ESTATÍSTICAS GERAIS ---\n");
    printf("Total de exemplares na biblioteca: %d\n", soma_total);
    printf("Total de títulos únicos cadastrados: %d\n", total_livros);
    printf("Total de usuários cadastrados: %d\n", total_usuarios);
    
    if (acervo[indexMaisEmprestado].vezes_emprestado > 0) {
        printf("\nLIVRO MAIS EMPRESTADO (Bônus):\n");
        printf("'%s' (Código %d) - Emprestado %d vezes ao longo do tempo.\n", 
            acervo[indexMaisEmprestado].titulo, 
            acervo[indexMaisEmprestado].codigo, 
            acervo[indexMaisEmprestado].vezes_emprestado);
    } else {
        printf("\nNenhum livro foi emprestado ainda.\n");
    }
    pausar();
}
