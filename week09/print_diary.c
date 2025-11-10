#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print the contents of the file `$HOME/.diary` to stdout.
// snprintf is a convenient function for constructing the pathname of the diary file.

int main(void) {
    char *home = getenv("HOME");
    // Length of home env variable + /.diary + null terminator
    int string_len = strlen(home) + 7 + 1;
    char *full_pathname = malloc(string_len);

    snprintf(full_pathname, string_len, "%s/.diary", home);

    // Open the file for reading
    FILE *fp = fopen(full_pathname, "r");

    // Print everything in the file out
    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }

}