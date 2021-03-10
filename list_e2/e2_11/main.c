#include <stdio.h>

void swap(int *x, int *y);

int main() {
    int quantity_of_numbers = 3;
    int i, j;
    int numbers[quantity_of_numbers];
    int numbers_array_length = quantity_of_numbers - 1;

    for (i = 0; i < quantity_of_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < numbers_array_length; i++) {
        for (j = 0; j < numbers_array_length - i; j++) {
            numbers[j] > numbers[j + 1] ? swap(&numbers[j], &numbers[j+1]) : "";
        }
    }

    for (i = 0; i < quantity_of_numbers; i++) {
        printf("%d\n", numbers[i]);
    }
}

void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

/*
E11) Faça um programa que leia três números e os apresente em ordem crescente. Imprima um número em cada linha. Não apresente texto para a leitura dos três números.


*/
