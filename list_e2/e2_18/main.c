#include <stdio.h>
typedef enum { false, true } bool;

int isBit(int nro, int bit) {
    return (nro >> bit) & 1U;
}

void func(char vet[], int num) {
    int bit, count;

    for (bit = 0; bit <= 31; bit++) {
        if (isBit(num, bit))
            vet[count] = '1';
        else
            vet[count] = '0';
        count++;
    }

    vet[32] = '\0';
}

void clearNumber(char vet[]) {
    int i, count = 0;
    bool startPrint = false;

    for (i = 31; i >= 0; i--) {
        if (vet[i] == '1')
            startPrint = true;

        if (startPrint) 
            count++;
    }
    vet[count] = '\0';
}

int main() {
    int num;
    char str[33];
    scanf("%d", &num);
    func(str, num);
    clearNumber(str);
    printf("%s\n", str);
}

/*
E18) Crie uma segunda versão da função anterior, em que seja removido os zeros a esquerda da string.


*/
