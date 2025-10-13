#include <stdio.h>
#include <assert.h>
#include <stdint.h>



// Reverse the order of the bits in variable w
uint32_t reverseBits(uint32_t w) {
    // Create a return variable
    uint32_t retval = 0;

    for (int i = 0; i < 32; i++) {
        // Read through OG value (w) from right to left
        // Mask below has the bit set to position i
        uint32_t mask = 0b1 << i;

        // is_set will be a non-zero value if the bit at position i is set
        uint32_t is_set = w & mask;

        // Now if the bit is set, we will set the bit in retval
        // but from left to right as loop continues
        if (is_set) {
            retval = retval | (1u << 31 - i);
        }
    }

    // Make sure to return the value!!
    return retval;
}

// testing
int main(void) {
    uint32_t w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}