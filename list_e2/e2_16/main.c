#include <stdio.h>

int main() {
    int num_a = 85;
    char num_a_hexa = 0x55;
    int num_a_bit = ~(0x55);
    // printf("a) %x %x %x\n", num_a, num_a_hexa, num_a_bit);
    printf("a) %x\n", num_a_bit);

    int num_b = 9;
    char num_b_hexa = 0x09;
    int num_b_bit = (0x09 << 2);
    // printf("b) %x %x %x\n", num_b, num_b_hexa, num_b_bit);
    printf("b) %x\n", num_b_bit);
    
    int num_c = 9;
    char num_c_hexa = 0x09;
    int num_c_bit = (0x09 >> 2);
    // printf("c) %x %x %x\n", num_c, num_c_hexa, num_c_bit);
    printf("c) %x\n", num_c_bit);

    int num_d = 240;
    char num_d_hexa = 0xFF;
    int num_d_bit = (0xFF >> 2);
    // printf("d) %x %x %x\n", num_d, num_d_hexa, num_d_bit);
    printf("d) %x\n", num_d_bit);

    int num_e = 240;
    char num_e_hexa = 0xFF;
    int num_e_bit = (0xFF << 2);
    // printf("e) %x %x %x\n", num_e, num_e_hexa, num_e_bit);
    printf("e) %x\n", num_e_bit);
}

/*
E16) Faça um programa que apresente (imprima com %x os resultados das expressões):
a) O valor decimal e em hexadecimal de 0x55 e do resultado do operador ~0x55
b) O valor decimal e em hexadecimal de 0x09 e o resultado da operação 0x09 << 2
c) O valor decimal e em hexadecimal de 0x09 e o resultado da operação 0x09 >> 2
d) O valor decimal e em hexadecimal de 0xFF e o resultado da operação 0xFF >> 2
e) O valor decimal e em hexadecimal de 0xFF e o resultado da operação 0xFF << 2

output esperado:
a) ffffffaa
b) 24
c) 2
d) 3f
e) 3fc

ATENÇÃO: a resposta acima não corresponde ao enunciado. O enunciado pede para apresentar os valores em decimal,
hexadecimal e o resultado da expressão. Mas apenas o resultado da expressão está sendo considerado.
*/
