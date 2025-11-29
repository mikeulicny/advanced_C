#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdckdint.h>  // in C23, added std checked int header

int main(void) {
    int a = INT_MAX - 10;
    int b = 11234;
    int c;

    bool overflow = ckd_add(&c, a, b);
    bool overflow1 = ckd_sub(&c, a, b);
    bool overflow2 = ckd_mul(&c, a, b);
    // If pre C23, there are some builtin headers that can do the same
    // thing. Some arguments are flipped around.
    // __builtin_add_overflow(a, b, &c);

    printf("overflow: %d\n", overflow);
    printf("%d + %d = %d\n", a, b, c);
    return 0;
}
