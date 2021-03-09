#include <stdio.h>

int main() {
    int x = 5, y = -10;
    printf("x=%d y=%d\n", x, y);
    
    x = x + y; // x: 15 y:10
    y = x - y; // y: 5 x: 15
    x = x - y; // x: 10

    printf("x=%d y=%d\n", x, y);
}

/*
E06) Faça um programa que faça a operação de swap entre as variáveis x e y, sem o uso de uma terceira variável, utilizando apenas operadores aritméticos.

Complemente o código abaixo ( o código abaixo deve ser informado para o farmalg):

int main( void ) {
int x=5, y=-10;
printf("x=%d y=%d\n",x,y);
printf("x=%d y=%d\n",x,y);
}
*/
