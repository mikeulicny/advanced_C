#include <stdio.h>

// Two ways to define constants in C
// define will textually replace during precompile
// #define LEN 10

// static const will provide type checking, but cannot be used to declare a static array

// Use constexpr to be able to evaluate variables at compile time
constexpr size_t len = 10;
constexpr int xs[len] = {1, 2, 3, 4};   // we can also do it with arrays

// Can also use it with structs
struct foo {
    int a;
    int b;
};

constexpr struct foo f = { .a = 1, .b = 2 };

// Can use it with strings also, but can only initialize it as NULL
constexpr char *s = NULL;

int main(void) {

    for (size_t i = 0; i < len; i++)
        printf("%d\n", xs[i]);

    printf("a=%d\n", f.a);

    return 0;
}
