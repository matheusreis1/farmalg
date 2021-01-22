#include <stdio.h>

int main() {
    float number, number_float;
    int number_int;

    scanf("%f", &number);

    number_int = number;
    number_float = number - number_int;

    printf("%d\n", number_int);
    printf("%f", number_float);
}

/*
E1_01) Faça um programa que leia um número de ponto flutuante e apresente em linhas separadas a parte inteira e a parte fracionária.
*/
