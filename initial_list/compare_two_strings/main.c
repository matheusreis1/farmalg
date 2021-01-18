#include <stdio.h>

int main() {
    char str1[32], str2[32];
    int aux, i;

    scanf("%s", &str1);
    scanf("%s", &str2);

    /* verify char by char until it's different or until it's final of string */
    while (str1[i] == str2[i] && str1[i] != '\0'){
        i++;
    }

    if (str1[i] > str2[i])
        aux = 1;
    else if (str1[i] < str2[i])
        aux = -1;

    printf("%d", aux);
}

/*
Faça um programa que leia duas strings, compare as strings e apresente na tela os valores "0" se forem iguais, "-1" se str1 for menor que str2, caso contrário "1".

Não deverá utilizar as funções da string.h (strcmp, stricmp, strncmp etc)

Atenção não apresente nada diferente disso.

Ex 1:
input:
ana
Ana
output
1
*/
