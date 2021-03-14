#include <stdio.h>

int main() {
    float number;
    scanf("%f", &number);

    if ((number - (int)number) >= 0.5) {
        number = (int)number + 1;
    }

    printf("%d\n", (int)number);
}

/*
E24) Faça um programa que leia um número de ponto flutuante e apresente o resultado do valor inteiro arredondado. 
Não use funções da biblioteca. Dica: use o cast para inteiros.

Exemplo:
Input:
3.9
Output
4


*/
