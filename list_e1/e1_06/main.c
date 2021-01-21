#include <stdio.h>

int main() {
    int number = 1;

    while( number ) {
        scanf("%d", &number);
        if ( number ) {
            even_or_odd(number);
        }
    }

}

void even_or_odd(int number) {
    ( number % 2 == 0 ) ? printf("%d par\n", number) : printf("%d impar\n", number);
}

/*
E1_06) Faça um programa que leia uma lista de números inteiros terminados por 0, para cada número lido o programa deve informar
 o número e se o número é par ou ímpar. Não utilize vetores/matrizes.

mostre apenas "par" ou "impar" (sem acentos).
*/
