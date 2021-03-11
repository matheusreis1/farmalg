#include <stdio.h>

int mdc(num_a, num_b) {
    // Algoritmo de Euclidade
    // obter o resto da divisao do numero da esquerda (maior) pelo numero da direita, 
    // o numero da esquerda vai ser igualado ao numero da direita
    // o numero da direita vai ser igualado ao resto
    // ate que o resto seja diferente de 0
    int resto;

    do {
        resto = num_a % num_b;

        num_a = num_b;
        num_b = resto;
    } while (resto != 0);

    return num_a;
}

int main(void) {
    int num_a, num_b;
    scanf("%d", &num_a);
    scanf("%d", &num_b);

    printf("%d", mdc(num_a, num_b));
}

/*
E15) Faça um programa que leia dois números inteiros e apresente o MAIOR DIVISOR COMUM entre os dois números.


*/
