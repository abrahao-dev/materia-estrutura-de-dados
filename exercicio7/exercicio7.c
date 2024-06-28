#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree *esq;
    struct tree *dir;
} arv;

// Função para criar um novo nó na árvore
arv* novoNo(int valor) {
    arv *novo = (arv*)malloc(sizeof(arv));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para excluir todas as folhas de uma árvore
arv* exclui_folhas(arv *a) {
    if (a == NULL) {
        return NULL;
    }

    // Se o nó atual é uma folha, excluí-lo
    if (a->esq == NULL && a->dir == NULL) {
        free(a);
        return NULL;
    }

    // Caso contrário, aplicar a função recursivamente nas subárvores
    a->esq = exclui_folhas(a->esq);
    a->dir = exclui_folhas(a->dir);

    return a;
}

// Função para imprimir a árvore em ordem
void imprime_arvore(arv *a) {
    if (a != NULL) {
        imprime_arvore(a->esq);
        printf("%d ", a->info);
        imprime_arvore(a->dir);
    }
}

int main() {
    // Criando uma árvore de exemplo
    arv *raiz = novoNo(1);
    raiz->esq = novoNo(2);
    raiz->dir = novoNo(3);
    raiz->esq->esq = novoNo(4);
    raiz->esq->dir = novoNo(5);
    raiz->dir->esq = novoNo(6);
    raiz->dir->dir = novoNo(7);

    printf("Árvore original: ");
    imprime_arvore(raiz);
    printf("\n");

    // Excluindo as folhas
    raiz = exclui_folhas(raiz);

    printf("Árvore após exclusão das folhas: ");
    imprime_arvore(raiz);
    printf("\n");

    return 0;
}
