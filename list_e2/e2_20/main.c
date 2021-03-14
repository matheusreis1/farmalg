#include <stdio.h>

int main() {
    int fim = 0;
    int opcao;

    while (!fim) {
        printf("1 - Opcao 1\n2 - Opcao 2\n3 - Opcao 3\n4 - Opcao 4\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Opcao %d\n", opcao);
                break;
            case 2:
                printf("Opcao %d\n", opcao);
                break;
            case 3:
                printf("Opcao %d\n", opcao);
                break;
            case 4:
                printf("Opcao %d\n", opcao);
                fim = 1;
                break;
        }
    }
}

/*
E20) Faça um programa que apresente um “menu com 4 opções”, leia um número inteiro entre 1 e 4 indicando 
a opção do menu e para cada valor lido imprima, correspondentemente, as frases “opção 1”, “opção 2”, “opção 3”, “opção 4”. 
Use o comando switch para resolver esse exercício. O programa encerra quando foi escolhido a opção 4, 
nas demais condições deverá apresentar o menu novamente e ler uma nova opção.
Sempre termine as strings com quebra de linha.

Exemplo:
output inicial:
1 - Opcao 1
2 - Opcao 2
3 - Opcao 3
4 - Opcao 4

input
1
4

output
Opcao 1
Opcao 4
*/
