#include <stdio.h>

int isBit(int nro, int bit) {
    return (nro >> bit) & 1U;
}

void func(char vet[], int num) {
    int bit, count;
    count = 31;

    for (bit = 0; bit <= 31; bit++) {
        if (isBit(num, bit))
            vet[count] = '1';
        else
            vet[count] = '0';
        count--;
    }

    vet[32] = '\0';
}

int main() {
    int num;
    char str[33];
    scanf("%d", &num);
    func(str, num);
    printf("%s\n", str);
}

/*
E17) Faça uma função que receba um vetor de char e um número e retorne no vetor o valores ‘0’ e ‘1’ 
correspondente ao valor binário de cada posição do número. Considere números de até 32 bits. (Considere o vetor com 33 posições).

Complemente o código (lembrem-se do include stdio.h):

void func(char vet[], int num) {
    // complemente o código
}

int main(void) {
    int num;
    char str[33];
    scanf("%d",&num);
    func(str,num);
    printf("%s\n",str);
}
*/
