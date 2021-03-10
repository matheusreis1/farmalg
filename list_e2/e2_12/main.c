#include <stdio.h>

int setBit(int nro, int bit) {
    // 1UL: is a constant that stands for 'unsigned long number_one = 1;'
    // <<: means left-shift
    nro = nro | (1UL << bit); 

    return nro;
}

int main() {
    int num, bit;
    scanf("%d %d", &num, &bit);
    printf("%d\n", setBit(num, bit));
}

/*
E12) Faça uma função setBit que receba dois parâmetros (nro e bit),
a função deve modificar o valor de nro de tal forma que o n-bit seja 
modificado para 1 e retornar o novo valor.

Complemente o código abaixo:

int setBit(int nro, int bit)
{
// complemente o código
}

int main(void) {
int num,bit;
scanf("%d %d",&num,&bit);
printf("%d\n",resetBit(num,bit));
}
*/
