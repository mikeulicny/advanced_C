#include <stdio.h>
#include <stdint.h>

int main(void) {
    int64_t a = 32;     // We can use stronger defined number types
    int b = 0xffaa33;   // Hex numbers
    int c = 0755;       // Octal numbers
    int d = 0b010111;   // Binary numbers

    printf("%ld\n", a);
    printf("%x\n", b);
    printf("%o\n", c);
    printf("%b\n", d);

    // Your octal integer can be used in places such as
    // 'mode' in the 'open()' function call. See 'man open 2'
    // This is your permissions in files/folders.
    return 0;
}
