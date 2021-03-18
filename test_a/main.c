#include <stdio.h>
#include <string.h>
#define valor_maximo(a, b) ((a) > (b) ? (a) : (b))

char* uniao(char* str_a, char* str_b);
char* intersecao(char* str_a, char* str_b);
char* xor(char* str_a, char* str_b);

int main() {
    char str_a[129];
    char str_b[129];
    
    gets(str_a);
    gets(str_b);

    char* uniao_msg;
    uniao_msg = uniao(&str_a, &str_b);

    char* intersecao_msg;
    intersecao_msg = intersecao(&str_a, &str_b);

    char* xor_msg;
    xor_msg = xor(&str_a, &str_b);

    printf("Uniao: %s\n", uniao_msg);
    printf("Intersecao: %s\n", intersecao_msg);
    printf("XOR: %s\n", xor_msg);

    free(uniao_msg);
    free(intersecao_msg);
    free(xor_msg);
}

char* uniao(char* str_a, char* str_b) {
    char* uniao;
    uniao = malloc(sizeof (char) * 129);

    int lenght_str_a = strlen(str_a);
    int lenght_str_b = strlen(str_b);
    int count = 0;
    int index_a, index_b, achou_char;

    while (str_a[count] != '\0') {
        uniao[count] = str_a[count];
        count++;
    }
    
    for (index_b = 0; index_b < lenght_str_b; index_b++) {
        achou_char = 0;
        for (index_a = 0; index_a < lenght_str_a; index_a++) {
            if (str_b[index_b] == str_a[index_a]) {
                achou_char = 1;
            }
        }
        if (achou_char == 0) {
            uniao[count] = str_b[index_b];
            count++;
        }
    }

    uniao[count] = '\0';

    return uniao;
}

char* intersecao(char* str_a, char* str_b) {
    char* intersecao;
    intersecao = malloc(sizeof (char) * 129);

    int lenght_str_a = strlen(str_a);
    int lenght_str_b = strlen(str_b);
    int count = 0;
    int index_a, index_b;

    for (index_a = 0; index_a < lenght_str_a; index_a++) {
        for (index_b = 0; index_b < lenght_str_b; index_b++) {
            if (str_a[index_a] == str_b[index_b]) {
                intersecao[count] = str_a[index_a];
                count++;
            }
        }
    }

    intersecao[count] = '\0';

    return intersecao;
}

char* xor(char* str_a, char* str_b) {
    char* xor;
    xor = malloc(sizeof (char) * 129);

    int lenght_str_a = strlen(str_a);
    int lenght_str_b = strlen(str_b);
    int count = 0;

    for (count = 0; count < valor_maximo(lenght_str_a, lenght_str_b); count++) {
        xor[count] = (char)(str_a[count] ^ str_b[count]);
    }

    xor[count] = '\0';

    return xor;
}

/*
1) Faça um programa que leia duas strings e apresente:

a. os símbolos que representem a união dos dois conjuntos;

b. os símbolos que façam parte da interseção dos dois conjuntos de símbolos;

c. os símbolos que correspondem a operação XOR (ou exclusivo) dos dois conjuntos.
*/
