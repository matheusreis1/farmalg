#include <stdio.h>

int main() {
    int num_a, num_b, num_c;

    scanf("%d", &num_a);
    scanf("%d", &num_b);
    scanf("%d", &num_c);

    int aux = num_a;

    if (num_a > num_b && num_a > num_c) {
        aux = num_a;
    } else if (num_b > num_a && num_b > num_c) {
        aux = num_b;
    } else {
        aux = num_c;
    }

    printf("%d", aux);
}

/*
Faça um programa que leia três valores inteiros (a,b,c) e apresente o maior número lido.

Exemplo de leitura
5
-1
10

Exemplo de saída
10
*/
