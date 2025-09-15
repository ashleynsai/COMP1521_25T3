// Prints the square of a number

// Very briefly introduced how we would translate this
// into MIPS in mips.s

#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    y = x * x;

    printf("%d\n", y);

    return 0;
}
