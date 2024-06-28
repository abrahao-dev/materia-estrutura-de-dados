#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copia_vetor(char *v, int tam) {
    // Aloca memória para a cópia do vetor
    char *copia = (char*)malloc((tam + 1) * sizeof(char)); // +1 para o caractere nulo
    if (copia == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Copia o conteúdo do vetor para a cópia
    strncpy(copia, v, tam);
    copia[tam] = '\0'; // Garante que a string seja terminada corretamente

    return copia;
}

int main() {
    char original[] = "Exemplo";
    int tam = strlen(original);

    // Chamando a função e imprimindo a cópia do vetor
    char *copia = copia_vetor(original, tam);
    printf("Original: %s\nCópia: %s\n", original, copia);

    // Liberando a memória alocada para a cópia
    free(copia);

    return 0;
}
