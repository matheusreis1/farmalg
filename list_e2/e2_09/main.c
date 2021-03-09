#include <stdio.h>

int main() {
    float number;
    scanf("%f", &number);

    printf("%d\n", (int)number);
    printf("%.3f\n", number - (int)number);
}

/*
E09) Faça um programa que leia um número de ponto flutuante e apresente em linhas separadas a parte inteira e a parte fracionária.

Na parte fracionário, usem %.3f e a qurba de linha na saída.
*/
