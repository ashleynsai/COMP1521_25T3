#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t value);

int main() {

    uint32_t value_to_extract_from = 151121;

    uint32_t bits = six_middle_bits(value_to_extract_from);

    printf("%d is the 6 middle bits of %d\n", bits, value_to_extract_from);
    
}

uint32_t six_middle_bits(uint32_t value) {
    // EXAMPLE
    // value is 0100 0111 0110 1MMM MMM0 1110 0101 0110 in binary
    // return   0000 0000 0000 0000 0000 0000 00MM MMMM
    
    // Mask
    uint32_t mask = 0b111111 << 13;
    return (value & mask) >> 13;
}