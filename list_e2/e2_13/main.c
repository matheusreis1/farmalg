#include <stdio.h>

int resetBit(int nro, int bit) {
    // 1UL: is a constant that stands for 'unsigned long number_one = 1;'
    // <<: means left-shift
    // ~: is a unary bitwise negation operator. It inverts all the bits of its operand. 
    nro = nro & ~(1UL << bit); 

    return nro;
}

int main() {
    int num, bit;
    scanf("%d %d", &num, &bit);
    printf("%d\n", resetBit(num, bit));
}

/*
E13) Faça uma função resetBit que receba dois parâmetros (nro e bit), 
a função deve modificar o valor de nro de tal forma que o n-bit seja 
modificado para 0 e retornar o novo valor.

Complemente o código abaixo:

int resetBit(int nro, int bit)
{
// complemente o código
}

int main(void) {
int num,bit;
scanf("%d %d",&num,&bit);
printf("%d\n",resetBit(num,bit));
}
*/
