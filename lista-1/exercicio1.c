#include <stdio.h>
#include <stdlib.h>

void menorValor(int vet[], int *menor, int *vezes, int tamanhoVet) {
  int i = 0;
  
  printf("O vetor é: \n");

  for (i = 0; i < tamanhoVet; i++) {
    printf("%d ", vet[i]);
}
  printf("\n Seu menor valor é: %d, ele apareceu %d", *menor,*vezes);
}

int main() {
  int tamanhoVet;
  int i = 0;
  int menor;
  int vezes=0;
  
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &tamanhoVet);

  int *vet = (int *) malloc(tamanhoVet * sizeof(int));

  for (i = 0; i < tamanhoVet; i++) {
      printf("Digite o %d valor:\n", i + 1);
      scanf("%d", &vet[i]);

    if(i==0){
      menor = vet[i];
    }

    if(vet[i]==menor){
      vezes++;
    }
    
    if (vet[i] < menor) {
      menor=vet[i];
    } 
  }

  menorValor(vet, &menor, &vezes, tamanhoVet);
  
}