#include <stdio.h>

// Write a c program `count_chars.c` that uses getchar to read in chars until Ctrl-D,
// prints the amount of characters entered

int main(void) {
    //int ch;
    int count = 0;

    // Create a loop
    // getchar() returns EOF when Ctrl-D is entered
    while (getchar() != EOF) {
        count++;
    }

    printf("Characters read in: %d\n", count);

    return 0;
}