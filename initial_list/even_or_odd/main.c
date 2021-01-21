#include <stdio.h>

int main() {
    int num_a;

    scanf("%d", &num_a);

    even_or_odd(num_a);
}

void even_or_odd(number) {
    ( number % 2 == 0 ) ? printf("%d par\n", number) : printf("%d impar\n", number);
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
