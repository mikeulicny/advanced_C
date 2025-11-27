#include <stdio.h>

// This should almost never be used, as the variable length array will be put on the stack!

int main(void) {

    int length = 12;    // this will always  be a variable length array
    int xs[length];
    for (int i = 0; i < length; i++)
        xs[i] = i * i;
    for (int i = 0; i < length; i++)
        printf("%d\n", xs[i]);

    // There is a function called alloca
    // see 'man alloca'
    // This does what we just did, but with slightly less code
    // it is still just as risky
    // 'alloca' can not return from a function either

    return 0;
}
