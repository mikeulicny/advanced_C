#include <stdio.h>
#include <stdint.h>

// Move these around to see different padding
// Largest first is typically the most efficient
struct foo {
    int8_t a;
    int32_t c;
    int16_t b;
} __attribute__((packed));  // use this syntax to pack the struct
                            // Useful for stuff such as reading/writing binary files

int main(void) {
    struct foo f = {
        .a = 0x11,
        .b = 0x2222,
        .c = 0x33333333,
    };
    printf("sizeof f = %zu\n", sizeof f);

    // Print out the bytes of the struct
    uint8_t *f_as_bytes = (uint8_t*)&f;
    for (int i = 0; i < sizeof f; i++)
        printf("%x ", f_as_bytes[i]);


    return 0;
}
