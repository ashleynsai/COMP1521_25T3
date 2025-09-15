#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

// What is wrong with the following code?

// Assuming we still want get_num_ptr to return a pointer, how can we fix this code?
// How does fixing this code affect each variable's location in memory?

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    // int x = 42;
    // return &x;

    int *x = malloc(sizeof(int));
    *x = 42;

    return x;
}