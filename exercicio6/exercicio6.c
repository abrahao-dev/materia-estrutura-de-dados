#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da árvore
typedef struct tree {
    int info;
    struct tree *esq;
    struct tree *dir;
} arv;

// Função para criar um novo nó
arv *criarNo(int valor) {
    arv *novoNo = (arv *)malloc(sizeof(arv));
    novoNo->info = valor;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// Função para contar o número de nós em uma árvore
int contarNos(arv *raiz) {
    if (raiz == NULL)
        return 0;
    else
        return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int main() {
    // Exemplo de criação de uma árvore
    arv *raiz = criarNo(1);
    raiz->esq = criarNo(2);
    raiz->dir = criarNo(3);
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(5);

    // Chamando a função para contar o número de nós na árvore
    int numNos = contarNos(raiz);
    printf("Numero de nos na arvore: %d\n", numNos);

    return 0;
}
