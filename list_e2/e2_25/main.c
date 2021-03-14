#include <stdio.h>

int potencia(int x, int n) {
    int i;
    int result = 1;

    for (i = 0; i < n; i++)
        result *= x;

    return result;
}

int main() {
    int base;
    int expoente;
    scanf("%d", &base);
    scanf("%d", &expoente);

    int resultado = potencia(base, expoente);

    printf("%d", resultado);
}

/*
E25) Faça um programa que leia dois valores inteiros (A e B) e apresente o resultado da operação de A elevado a B.


*/
