#include <stdio.h>
#include <sys/stat.h>

// Given 1+ command-line arguments which are the pathnames of files or directories,
// if the file or directory is publically-writeable, it should change it to be 
// not publically-writeable, leaving other permissions unchanged.

// It also should print a line to stdout
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;
        int stat_ret = stat(argv[i], &s);
        if (stat_ret == -1) {
            perror("stat");
            return 1;
        }

        // Our struct should be filled with the metadata of the file
        mode_t permissions = s.st_mode;

        // Check if others have write permission
        // If they do, chmod to not publically writeable
        // If they don't leave it alone

        // Check if permissions has S_IWOTH set
        // and operation because we're extracting
        if (permissions & S_IWOTH) {
            // Change the permissions to be not publically writable
            // we can not the mask and or it
            printf("Setting public write to off\n");
            int final_permissions = permissions & (~S_IWOTH);

            // Set the permissions
            chmod(argv[i], final_permissions);
        } else {
            printf("Public write is already off\n");
        }
    }
}