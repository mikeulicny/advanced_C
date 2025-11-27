#include <stdio.h>
#include <assert.h>

#define FOO 42

// assert at compile time
static_assert(FOO == 42, "FOO not equal to 42");    // message is optional


int main(void) {

    // int a = 1;
    // assert(a == 0); // will crash the program with SIGABRT

    // can also be used on constexpr
    constexpr int foo = 42;
    static_assert(foo == 41, "FOO not equal to 41");

    return 0;
}
