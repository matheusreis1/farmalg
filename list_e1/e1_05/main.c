#include <stdio.h>

int main() {
    int i, number, aux;

    while (i < 10) {
        scanf("%d", &number);
        if ( number > aux || i == 0) {
            aux = number;
        }
        i++;
    }

    printf("%d", aux);
}

/*
E1_05) Faça um programa que leia 10 números inteiros e apresente o maior (não utilize vetor/matriz).

loop que verifica todo valor com o anterior preenchido
*/
