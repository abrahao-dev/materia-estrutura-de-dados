#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

// Definição da estrutura do nó
typedef struct No {
    char especie[50];
    int quantidade;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(char especie[]) {
    No* novoNo = (No*)malloc(sizeof(No));
    strcpy(novoNo->especie, especie);
    novoNo->quantidade = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir uma nova espécie na árvore binária
No* adicionarEspecie(No* raiz, char especie[]) {
    if (raiz == NULL) {
        return criarNo(especie);
    }

    int resultadoComparacao = strcmp(raiz->especie, especie);

    if (resultadoComparacao == 0) {
        raiz->quantidade++;
    } else if (resultadoComparacao > 0) {
        raiz->esquerda = adicionarEspecie(raiz->esquerda, especie);
    } else {
        raiz->direita = adicionarEspecie(raiz->direita, especie);
    }

    return raiz;
}

// Função para contar o número total de espécies
int contarEspeciesUnicas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarEspeciesUnicas(raiz->esquerda) + contarEspeciesUnicas(raiz->direita);
}

// Função para contar o número total de árvores
int contarTotalArvores(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return raiz->quantidade + contarTotalArvores(raiz->esquerda) + contarTotalArvores(raiz->direita);
}

// Função para listar todas as espécies e suas quantidades
void listarTodasEspecies(No* raiz) {
    if (raiz != NULL) {
        listarTodasEspecies(raiz->esquerda);
        printf("| Espécie: %-30s | Quantidade: %d |\n", raiz->especie, raiz->quantidade);
        listarTodasEspecies(raiz->direita);
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n=========================================\n");
    printf("|        Seja bem-vindo ao ArvoreID      |\n");
    printf("=========================================\n");
    printf("|            MENU DE OPÇÕES             |\n");
    printf("=========================================\n");
    printf("| 1. Adicionar nova espécie de árvore   |\n");
    printf("| 2. Contar número total de espécies    |\n");
    printf("| 3. Contar número total de árvores     |\n");
    printf("| 4. Listar todas as espécies           |\n");
    printf("| 5. Sair                               |\n");
    printf("=========================================\n");
    printf("Escolha uma opção: ");
}

// Função para limpar a tela
void limparTela() {
    system(LIMPAR_TELA);
}

// Programa principal
int main() {
    No* raiz = NULL;
    int opcao;
    char especie[50];

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o nome da espécie: ");
                scanf("%s", especie);
                raiz = adicionarEspecie(raiz, especie);
                printf("\nEspécie adicionada com sucesso!\n");
                break;
            case 2:
                printf("\nNúmero total de espécies únicas: %d\n", contarEspeciesUnicas(raiz));
                break;
            case 3:
                printf("\nNúmero total de árvores: %d\n", contarTotalArvores(raiz));
                break;
            case 4:
                printf("\nListando todas as espécies:\n");
                printf("=========================================\n");
                listarTodasEspecies(raiz);
                printf("=========================================\n");
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

        if (opcao != 5) {
            printf("\nPressione Enter para continuar...");
            getchar();  // Captura o Enter
            getchar();  // Espera o Enter
        }

    } while (opcao != 5);

    return 0;
}
