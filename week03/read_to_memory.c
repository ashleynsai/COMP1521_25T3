// A simple program that will read 10 numbers into an array

#define N_SIZE 10

#include <stdio.h>

int main(void) {
    int i; // $t0
    int numbers[N_SIZE] = {0}; // All arrays must be put in data section

    // i = 0;
    // while (i < N_SIZE) {
    //     scanf("%d", &numbers[i]);
    //     i++;
    // }

loop_init:
    i = 0;

loop_cond:
    if (i >= N_SIZE) goto loop_end;
    
loop_body:
    scanf("%d", &numbers[i]);

loop_step:
    i++;
    goto loop_cond;

loop_end:
    return 0;
}