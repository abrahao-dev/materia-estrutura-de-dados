#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura produto
typedef struct produto
{
  int codigoID;
  char nomeProduto[50];
  int estoque;
  float precoVenda;
} produto;

int main(void) {
  int numeroDeProdutos;

  printf("Digite o número de produtos: ");
  scanf("%d", &numeroDeProdutos);

  // Array de produtos
  produto produtos[numeroDeProdutos];

  // Limpa o buffer de entrada
  setbuf(stdin, NULL);

  // Loop para inserir os dados dos produtos
  for (int i = 0; i < numeroDeProdutos; i++) {
      printf("Digite o ID do %dº Produto: ", i + 1);
      scanf("%d", &produtos[i].codigoID);

      printf("Digite o nome do %dº Produto: ", i + 1);
      scanf("%s", produtos[i].nomeProduto);

      printf("Digite o número de produtos no estoque do %dº Produto: ", i + 1);
      scanf("%d", &produtos[i].estoque);

      printf("Digite o preço de venda do %dº Produto: ", i + 1);
      scanf("%f", &produtos[i].precoVenda);
  }

  // Encontre o produto com o maior preço de venda
  float maiorPrecoVenda = produtos[0].precoVenda;
  int indexMaiorPreco = 0;
  for (int i = 1; i < numeroDeProdutos; i++) {
      if (produtos[i].precoVenda > maiorPrecoVenda) {
          maiorPrecoVenda = produtos[i].precoVenda;
          indexMaiorPreco = i;
      }
  }

  // Encontre o produto com a maior quantidade disponível no estoque
  int maiorEstoque = produtos[0].estoque;
  int indexMaiorEstoque = 0;
  for (int i = 1; i < numeroDeProdutos; i++) {
      if (produtos[i].estoque > maiorEstoque) {
          maiorEstoque = produtos[i].estoque;
          indexMaiorEstoque = i;
      }
  }

  // Imprimir os resultados
  printf("Produto com o maior preço de venda:\n");
  printf("ID: %d, Nome: %s, Estoque: %d, Preço de Venda: %.2f\n", produtos[indexMaiorPreco].codigoID, produtos[indexMaiorPreco].nomeProduto, produtos[indexMaiorPreco].estoque, produtos[indexMaiorPreco].precoVenda);

  printf("Produto com a maior quantidade disponível no estoque:\n");
  printf("ID: %d, Nome: %s, Estoque: %d, Preço de Venda: %.2f\n", produtos[indexMaiorEstoque].codigoID, produtos[indexMaiorEstoque].nomeProduto, produtos[indexMaiorEstoque].estoque, produtos[indexMaiorEstoque].precoVenda);

  return 0;
}
