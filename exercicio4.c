#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista
typedef struct no {
    int valor;
    struct no *proximo;
} no;

// Função para concatenar duas listas encadeadas
no* concatena_listas(no* L1, no* L2) {
    // Se uma das listas for vazia, retorna a outra lista
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }

    // Encontra o último nó da primeira lista
    no* temp = L1;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }

    // Concatena a segunda lista ao último nó da primeira lista
    temp->proximo = L2;

    // Retorna a primeira lista agora concatenada
    return L1;
}

// Função para imprimir os elementos de uma lista
void imprime_lista(no* lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

// Função principal
int main() {
    // Criação de duas listas vazias
    no *L1 = NULL;
    no *L2 = NULL;

    // Populando as listas com alguns valores para teste
    for (int i = 1; i <= 5; i++) {
        no *novo_no = (no*)malloc(sizeof(no));
        novo_no->valor = i;
        novo_no->proximo = NULL;

        if (L1 == NULL) {
            L1 = novo_no;
        } else {
            no *temp = L1;
            while (temp->proximo != NULL) {
                temp = temp->proximo;
            }
            temp->proximo = novo_no;
        }
    }

    for (int i = 6; i <= 10; i++) {
        no *novo_no = (no*)malloc(sizeof(no));
        novo_no->valor = i;
        novo_no->proximo = NULL;

        if (L2 == NULL) {
            L2 = novo_no;
        } else {
            no *temp = L2;
            while (temp->proximo != NULL) {
                temp = temp->proximo;
            }
            temp->proximo = novo_no;
        }
    }

    // Exibindo as listas antes da concatenação
    printf("Lista L1 antes da concatenação: ");
    imprime_lista(L1);

    printf("Lista L2 antes da concatenação: ");
    imprime_lista(L2);

    // Concatenando as listas
    L1 = concatena_listas(L1, L2);

    // Exibindo a lista concatenada
    printf("Lista concatenada: ");
    imprime_lista(L1);

    return 0;
}
