// A simple program that will print 10 numbers from an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i; // $t0
    // Arrays declared in data section
    int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // i = 0;
    // while (i < N_SIZE) {
    //     printf("%d\n", numbers[i]);
    //     i++;
    // }
loop_init:
    i = 0;

loop_cond:
    if (i >= N_SIZE) goto loop_end;
loop_body:
    printf("%d\n", numbers[i]);

loop_step:
    i++;
    goto loop_cond;

loop_end:
    return 0;
}