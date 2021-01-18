#include <stdio.h>

int main() {
    int num_a;

    scanf("%d", &num_a);

    oven_or_odd(num_a);
}

int oven_or_odd(number) {
    if (number % 2 == 0) {
        printf("%d par", number);
    } else {
        printf("%d impar", number);
    }
    return 0;
}
