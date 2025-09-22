// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    // Do not need to "declare" variables in MIPS
    int x, y;
    // t0 - x
    // t1 - y

    // Syscall whenever interacting with terminal
    printf("Enter a number: ");
    scanf("%d", &x);

    // Put all loops/if statements into the format:
    // if (one condition) goto label;
    // else, else if, for, while - banned in simplified C

    if (x > SQUARE_MAX) goto invalid_x;
    goto valid_x;

valid_x:
    y = x * x;
    printf("%d\n", y);
    goto epilogue;

invalid_x:
    printf("square too big for 32 bits\n");
    
    // if (x > SQUARE_MAX) {
    //     printf("square too big for 32 bits\n");
    // } else {
    //     y = x * x;
    //     printf("%d\n", y);
    // }

epilogue:
    return 0;
}