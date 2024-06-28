#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no;

int remove_menor(no *lista) {
    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return -1;
    }

    // Encontrar o menor valor na lista e seu nó anterior
    no *menor_anterior = NULL;
    no *atual = lista;
    no *menor = lista;
  
    while (atual->proximo != NULL) {
        if (atual->proximo->valor < menor->valor) {
            menor_anterior = atual;
            menor = atual->proximo;
        }
        atual = atual->proximo;
    }

    // Remover o menor valor da lista
    if (menor_anterior == NULL) {
        lista = lista->proximo;
    } else {
        menor_anterior->proximo = menor->proximo;
    }

    int valor_menor = menor->valor;
    free(menor);

    return valor_menor;
}

int main() {
    // Exemplo de uso
    no *lista = (no *)malloc(sizeof(no));
    lista->valor = 5;
    lista->proximo = NULL;

    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->valor = 3;
    novo_no->proximo = NULL;
    lista->proximo = novo_no;

    novo_no = (no *)malloc(sizeof(no));
    novo_no->valor = 7;
    novo_no->proximo = NULL;
    lista->proximo->proximo = novo_no;

    printf("Removido o menor valor: %d\n", remove_menor(lista));

    return 0;
}