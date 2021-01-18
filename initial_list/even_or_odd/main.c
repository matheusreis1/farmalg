#include <stdio.h>

int main() {
    int num_a;

    scanf("%d", &num_a);

    oven_or_odd(num_a);
}

int oven_or_odd(number) {
    if (number % 2 == 0) {
        printf("%d par", number);
    } else {
        printf("%d impar", number);
    }
    return 0;
}

/*
Faça um programa que leia um número e apresente o número lido e a seguir se ele é "par" ou "impar" (sem acento).

Ex:
input
1
saída
1 impar

Ex 2:
input
2
saída
2 par
*/
