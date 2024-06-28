#include <stdio.h>

int exercicio1(void) {
  float matriz[10][3];
  int contador = 0;

  for (int i = 0; i < 10; i++) {
      printf("Digite o peso da pessoa %d (em kg): ",i + 1);
      scanf("%f", &matriz[i][0]);

      printf("Digite a altura da pessoa %d (em metros): ", i + 1);
      scanf("%f", &matriz[i][1]);

      // Cálculo do IMC
      matriz[i][2] = matriz[i][0] / (matriz[i][1] * matriz[i][1]);

      // Verificando se o IMC é maior que 25
      if (matriz[i][2] > 25) {
        contador++;
    }
  }

  // Saída de dados (matriz), irá representar as 10 pessoas nas colunas peso altura IMC de forma organizada e limitando os números do tipo float a 2 casas decimais
  printf("\n(Peso | Altura | IMC):\n");
  for (int i = 0; i < 10; i++) {
      printf("%.2f\t%.2f\t%.2f\n", matriz[i][0], matriz[i][1], matriz[i][2]);
  }

  printf("\nNúmero de pessoas com IMC maior que 25: %d\n", contador);

  return 0;
}