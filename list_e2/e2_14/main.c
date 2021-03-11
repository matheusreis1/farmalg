#include <stdio.h>

int isBit(int nro, int bit) {
    // 1U: is a constant that stands for 'unsigned int number_one = 1;'
    // >>: means right-shift

    return (nro >> bit) & 1U;
}

int main(void) {
    int num, bit;
    scanf("%d %d", &num, &bit);
    printf("%d\n", isBit(num, bit));
}

/*
E14) Faça uma função isBit que receba dois parâmetros (nro e bit), 
a função deve retornar FALSO (0) se o n-bit estiver com valor 0 ou, 
no caso contrário, retornar VERDADEIRO.

Complemente o código abaixo:

int isBit(int nro, int bit)
{
// complemente o código
}

int main(void) {
int num,bit;
scanf("%d %d",&num,&bit);
printf("%d\n", isBit(num,bit) );
}
*/
