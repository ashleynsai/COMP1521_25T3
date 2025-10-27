#include <stdint.h>
#include <stdio.h>
#include <assert.h>

typedef struct six_bit_groups {
    uint8_t middle_bits;
    uint8_t lower_bits;
} six_bit_groups_t;

/*
Example:

    01100010   10101101   11001100   10010011
                    ^^^   ^^^          ^^^^^^
                      middle            lower
                       = 46             = 19
=

*/

six_bit_groups_t get_bit_groups(uint32_t value) {
    // TODO: extract the middle and lower 6 bits
    //       and return them through a struct
    six_bit_groups_t retval;
    uint32_t mask = 0x3f;
    //.           = 0b111111
    //.           = 63

    // Logical shift and then and operation
    retval.middle_bits = (value >> 13) & mask;

    // And operation
    retval.lower_bits = value & mask;

    return retval;
}

int main() {
    six_bit_groups_t ret = get_bit_groups(1655557267);
    assert(ret.middle_bits == 46);
    assert(ret.lower_bits == 19);
    printf("All tests pass!\n");
}