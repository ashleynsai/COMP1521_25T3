#include <stdio.h>
#include <sys/stat.h>

// Write a C program, `print_perms.c`, which is given 1+ command-line arguments which are the pathnames of files.
// Print to stdout the permissions in octal form.
// How would we change the octal into something more readable like "rwxr-xr-x"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        // get the metadata of the filename provided
        struct stat s;
        stat(argv[i], &s);

        // access the permissions within the struct stat
        mode_t permissions = s.st_mode;

        // print it out in octal form
        printf("The permissions for %s in octal: %o\n", argv[i], permissions);
    }
}