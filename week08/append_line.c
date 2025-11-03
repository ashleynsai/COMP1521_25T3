#include <stdio.h>
#include <string.h>
#include <errno.h>

// This program is given one command-line argument, the name of a file,
// and which reads a line from stdin and appends it to the specified file.
int main(int argc, char *argv[]) {

    // What does fopen do? What are its parameters? What is the return value
    FILE *stream = fopen(argv[1], "a");

    // Error checking
    if (stream == NULL) {
        // Can use either method to convey error
        // - if function failed errno is set so you can use perror
        perror("fopen errored"); // prints "fopen errored: No such file or directory"

        // - if you're enforcing your own rules (e.g. valid magic number or checksum), use fprintf
        fprintf(stderr, "%s: %s", argv[1], strerror(errno));
    }

    // read in a line from stdin
    char buffer[100];
    fgets(buffer, 100, stdin); // can use other functions like scanf too

    fprintf(stream, "%s", buffer); // can use other functinos like fputc and fputs

    fclose(stream);

    return 0;
}

// What are some circumstances that fopen returns null
// - file doesn't exist (for read)
// - permission errors
// - mode does not exist