#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

#define TAMANHO_TABELA 100

// Estrutura para armazenar os dados do pedido
typedef struct Pedido {
    int id;
    char nomeCliente[50];
    char descricao[100];
    struct Pedido* proximo;
} Pedido;

// Função hash simples para calcular o índice da tabela de hash
int hash(int id) {
    return id % TAMANHO_TABELA;
}

// Função para criar um novo pedido
Pedido* criarPedido(int id, char* nomeCliente, char* descricao) {
    Pedido* novoPedido = (Pedido*)malloc(sizeof(Pedido));
    novoPedido->id = id;
    strcpy(novoPedido->nomeCliente, nomeCliente);
    strcpy(novoPedido->descricao, descricao);
    novoPedido->proximo = NULL;
    return novoPedido;
}

// Função para adicionar um pedido à tabela de hash
void adicionarPedido(Pedido* tabela[], int id, char* nomeCliente, char* descricao) {
    int indice = hash(id);
    Pedido* novoPedido = criarPedido(id, nomeCliente, descricao);

    if (tabela[indice] == NULL) {
        tabela[indice] = novoPedido;
    } else {
        Pedido* atual = tabela[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoPedido;
    }
    printf("Pedido adicionado com sucesso!\n");
}

// Função para recuperar informações de um pedido
void recuperarPedido(Pedido* tabela[], int id) {
    int indice = hash(id);
    Pedido* atual = tabela[indice];

    while (atual != NULL) {
        if (atual->id == id) {
            printf("Pedido encontrado:\n");
            printf("ID: %d\n", atual->id);
            printf("Nome do Cliente: %s\n", atual->nomeCliente);
            printf("Descrição: %s\n", atual->descricao);
            return;
        }
        atual = atual->proximo;
    }
    printf("Pedido não encontrado!\n");
}

// Função para imprimir todos os pedidos na tabela de hash
void imprimirPedidos(Pedido* tabela[]) {
    printf("\n==================== Lista de Pedidos ====================\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Pedido* atual = tabela[i];
        if (atual != NULL) {
            printf("Pedidos no índice %d:\n", i);
            while (atual != NULL) {
                printf("ID: %d, Nome do Cliente: %s, Descrição: %s\n", atual->id, atual->nomeCliente, atual->descricao);
                atual = atual->proximo;
            }
            printf("--------------------------------------------------------\n");
        }
    }
}

// Função para liberar a memória alocada para a tabela de hash
void liberarTabela(Pedido* tabela[]) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Pedido* atual = tabela[i];
        while (atual != NULL) {
            Pedido* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

// Função para limpar a tela
void limparTela() {
    system(LIMPAR_TELA);
}

// Função para exibir o menu com elementos visuais
void exibirMenu() {
    printf("\n=========================================\n");
    printf("|        Bem-vindo ao Sistema de        |\n");
    printf("|            Pedidos Cafeteria          |\n");
    printf("=========================================\n");
    printf("| 1. Adicionar novo pedido              |\n");
    printf("| 2. Recuperar pedido                   |\n");
    printf("| 3. Imprimir todos os pedidos          |\n");
    printf("| 4. Sair                               |\n");
    printf("=========================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Pedido* tabela[TAMANHO_TABELA] = { NULL };
    int opcao, id;
    char nomeCliente[50], descricao[100];

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Captura o Enter deixado no buffer pelo scanf

        switch (opcao) {
            case 1:
                printf("Digite o ID do pedido: ");
                scanf("%d", &id);
                getchar(); // Captura o Enter deixado no buffer pelo scanf
                printf("Digite o nome do cliente: ");
                fgets(nomeCliente, sizeof(nomeCliente), stdin);
                nomeCliente[strcspn(nomeCliente, "\n")] = '\0'; // Remove o newline
                printf("Digite a descrição do pedido: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0'; // Remove o newline
                adicionarPedido(tabela, id, nomeCliente, descricao);
                break;
            case 2:
                printf("Digite o ID do pedido a ser recuperado: ");
                scanf("%d", &id);
                recuperarPedido(tabela, id);
                break;
            case 3:
                imprimirPedidos(tabela);
                break;
            case 4:
                printf("Saindo...\n");
                liberarTabela(tabela);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        if (opcao != 4) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Captura o Enter
        }

    } while (opcao != 4);

    return 0;
}
