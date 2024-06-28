#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} lista;

// Função para inserir um elemento no final da lista
lista* insereFinal(lista *l, int valor) {
    lista *novo = (lista*) malloc(sizeof(lista));
    novo->info = valor;
    novo->prox = NULL;

    if (l == NULL) {
        return novo;
    }

    lista *aux = l;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

// Função para imprimir os elementos da lista
void imprimeLista(lista *l) {
    while (l != NULL) {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}

// Função para retirar um elemento de uma posição determinada
lista* retiraDaPosicao(lista *no, int pos) {
    if (pos < 0 || no == NULL)
        return no;

    if (pos == 0) {
        lista *temp = no->prox;
        free(no);
        return temp;
    }

    lista *prev = NULL;
    lista *curr = no;
    for (int i = 0; curr != NULL && i < pos; i++) {
        prev = curr;
        curr = curr->prox;
    }

    if (curr == NULL)
        return no;

    prev->prox = curr->prox;
    free(curr);
    return no;
}

// Função para comparar o tamanho das listas encadeadas
int comp_tamanho(lista *l1, lista *l2) {
    int tamanho_l1 = 0, tamanho_l2 = 0;

    while (l1 != NULL) {
        tamanho_l1++;
        l1 = l1->prox;
    }

    while (l2 != NULL) {
        tamanho_l2++;
        l2 = l2->prox;
    }

    if (tamanho_l1 == tamanho_l2)
        return 0;
    else if (tamanho_l1 < tamanho_l2)
        return -1;
    else
        return 1;
}

int main() {
    lista *l1 = NULL;
    lista *l2 = NULL;

    // Inserindo elementos na lista l1
    l1 = insereFinal(l1, 1);
    l1 = insereFinal(l1, 2);
    l1 = insereFinal(l1, 3);

    // Inserindo elementos na lista l2
    l2 = insereFinal(l2, 1);
    l2 = insereFinal(l2, 2);
    l2 = insereFinal(l2, 3);
    l2 = insereFinal(l2, 4);

    // Imprimindo as listas
    printf("Lista 1: ");
    imprimeLista(l1);
    printf("Lista 2: ");
    imprimeLista(l2);

    // Testando as funções
    printf("\nComparação de tamanho: %d\n", comp_tamanho(l1, l2));

    l1 = retiraDaPosicao(l1, 1); // Removendo o segundo elemento da lista l1
    printf("\nLista 1 após remover o segundo elemento: ");
    imprimeLista(l1);

    return 0;
}
