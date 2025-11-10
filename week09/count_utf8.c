#include <stdio.h>

int length_codepoint(char codepoint) {
    if ((codepoint & 0b10000000) == 0) {
        return 1;
    } else if ((codepoint & 0b11100000) == 0b11000000) {
        return 2;
    } else if ((codepoint & 0b11110000) == 0b11100000) {
        return 3;
    } else {
        return 4;
    }
}

// reads a null-terminated UTF-8 string as a command line argument and 
// counts how many Unicode characters (code points) it contains. 
// Assume that all codepoints in the string are valid.
int main(int argc, char *argv[]) {
    char *str = argv[1];
    int count = 0;

    while (*str != '\0') {
        // Read the first byte of the codepoint
        // check the length from that first byte
        int length = length_codepoint(*str);
        str += length;
        count++;
    }

    printf("the amount of codepoints: %d\n", count);
}
