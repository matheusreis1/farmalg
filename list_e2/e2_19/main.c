#include <stdio.h>
#define MAX_NUMBER_LENGTH 32

void reverse(char *x, int begin, int end) {
    char c;

    if (begin >= end)
        return;

    c = *(x + begin);
    *(x + begin) = *(x + end);
    *(x + end) = c;

    reverse(x, ++begin, --end);
}

int main() {
    int num, tempNum;
    scanf("%d", &num);

    char numBin[MAX_NUMBER_LENGTH];
    int index = 0;
    tempNum = num;

    while (tempNum != 0) {
        numBin[index] = (tempNum % 2) + '0';

        tempNum /= 2;
        index++;
    }

    numBin[index] = '\0'; // here numBin (binary) is in reverse order

    int begin, end, count = 0;

    while (numBin[count] != '\0')
        count++;

    end = count - 1;

    reverse(numBin, begin, end);

    printf("%d\n%x\n%o\n%s", num, num, num, numBin);
}

/*
E19) Faça um programa que leia um número inteiro e apresente o valor correspondente em 
decimal, hexadecimal, octal e binário. Cada número em uma linha (respeite a ordem dos elementos).

3:
3 // decimal
3 // hexa
3 // octal
11 // binario
*/
