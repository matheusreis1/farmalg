#include <stdio.h>

int main() {
    int quantity_of_numbers = 3;
    int i, j, temp;
    int numbers[quantity_of_numbers];
    int numbers_array_length = quantity_of_numbers - 1;

    for (i = 0; i < quantity_of_numbers; i++) {
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < numbers_array_length; i++) { // to keep track of number of cycles
        for (j = 0; j < numbers_array_length - i; j++) { // to compare the elements within the particular cycle
            // swap if one element is greater than its adjacent element
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < quantity_of_numbers; i++) {
        printf("%d\n", numbers[i]);
    }
}

/*
E1_07) Faça um programa que leia três números e os apresente em ordem crescente.
Apresente um número por linha.
*/
