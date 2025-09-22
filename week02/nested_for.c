// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {
	int i, j;
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 0; j < i; j++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

loop_i_init:
	i = 1;

loop_i_cond:
	// Do the opposite or ending condition of og
	if (i > 10) goto loop_i_end;

loop_i_body:
loop_j_init:
	j = 0;

loop_j_cond:
	if (j >= i) goto loop_j_end;

loop_j_body:
	printf("*");

loop_j_step:
	j++;
	goto loop_j_cond;

loop_j_end:
	printf("\n");

loop_i_step:
	i++;
	goto loop_i_cond;

loop_i_end:
    return 0;
}