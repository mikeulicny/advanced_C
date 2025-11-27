#include <stdio.h>

// This will output a size of 2, if we remove the ': short' it will output the
// default size of 4
enum foo : short {
    FOO_A,
    FOO_B
};

int main (void) {

    enum foo x = FOO_A;
    printf("sizeof(x) = %lu\n", sizeof x);

    return 0;
}
