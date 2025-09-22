# Intro to MIPS



1. What is mipsy (and mipsy_web), and what do we use them for in COMP1521?

- mipsy is a emulator that simulates what MIPS assembler code would do on a MIPS CPU



5. Translate this C program so it uses goto rather than if/else.

   Then translate it to MIPS assembler.   **demo in `square.(c|s)`**

   ```c
   // Squares a number, unless its square is too big for a 32-bit integer.
   // If it is too big, prints an error message instead.
   
   #include <stdio.h>
   
   #define SQUARE_MAX 46340
   
   int main(void) {
       int x, y;
   
       printf("Enter a number: ");
       scanf("%d", &x);
   
       if (x > SQUARE_MAX) {
           printf("square too big for 32 bits\n");
       } else {
           y = x * x;
           printf("%d\n", y);
       }
   
       return 0;
   }
   ```



8. Translate this C program so it uses goto rather than if/else.

   Then translate it to MIPS assembler. **demo in `nested_for.(c|s)`**

   ```c
   // Prints a right - angled triangle of asterisks, 10 rows high.
   
   #include <stdio.h>
   
   int main(void) {
       for (int i = 1; i <= 10; i++) {
           for (int j = 0; j < i; j++) {
               printf("*");
           }
           printf("\n");
       }
       return 0;
   }
   ```