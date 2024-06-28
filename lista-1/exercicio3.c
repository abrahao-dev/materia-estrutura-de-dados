#include <stdio.h>
#include <stdlib.h>

  int fibonacci(int n) {
      if (n <= 1)
          return n;
      else
          return fibonacci(n-1) + fibonacci(n-2);
  }

  int main() {
      int n;
      printf("Digite o valor de N para encontrar o N-ésimo termo da sequência de Fibonacci: ");
      scanf("%d", &n);

      int resultado = fibonacci(n);
      printf("O %dº termo da sequência Fibonacci é: %d\n", n, resultado);

      return 0;
  }