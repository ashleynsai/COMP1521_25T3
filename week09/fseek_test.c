#include <stdio.h>

int main() {
    FILE *fp = fopen("test_file", "w+");

    // Change offset to move file position past EOF or before the beginning
    // to see how it responds.
    int fseek_ret = fseek(fp, -100, SEEK_CUR);
    if (fseek_ret == -1) {
        perror("fseek");
        return 1;
    }

    fprintf(fp, "Hi can you see this");
}