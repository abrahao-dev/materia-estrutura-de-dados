#include <stdio.h>

float calcularDelta(float a, float b, float c) {
    return (b * b) - (4 * a * c);
}

int main() {
    float a, b, c;
  
    printf("Digite os valores de A da equação de segundo grau (ax^2 + bx + c): \n");
  
    scanf("%f", &a);

    printf("Digite os valores de B da equação de segundo grau (ax^2 + bx + c): \n");

    scanf("%f", &b);

    printf("Digite os valores de C da equação de segundo grau (ax^2 + bx + c): \n");

    scanf("%f", &c);

    float delta = calcularDelta(a, b, c);
    printf("Delta da equação: %.2f\n", delta);

    return 0;
}