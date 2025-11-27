#include <stdio.h>

// A keyword used on pointer declarations
// Hints to the compiler that for the lifetime of the pointer, no other pointer
// will be used to access the object to which it points

// When compiling this code, you have to use optimization 3 on
// gcc -O3 main.c

// Copy and run this code in compiler explorer to see the difference between the
// two functions in assembly

// This will compile to the following assembly
// updatePtrs:
//     mov    rax, QWORD PTR [rdx]
//     add    QWORD PTR [rdi], rax
//     mov    rax, QWORD PTR [rdx]
//     add    QWORD PTR [rsi], rax
//     ret
void updatePtrs(size_t *ptrA, size_t *ptrB, size_t *val) {
    *ptrA += *val;
    *ptrB += *val;
}

// This will compile to the following assembly
// updatePtrs_restrict:
//     mov    rax, QWORD PTR [rdx]
//     add    QWORD PTR [rdi], rax
//     add    QWORD PTR [rsi], rax
//     ret
void updatePtrs_restrict(size_t *restrict ptrA, size_t *restrict ptrB, size_t *restrict val) {
    *ptrA += *val;
    *ptrB += *val;
}

int main(void) {

    size_t a = 1, b = 2, c = 3;
    printf("Init:        a=%zu, b=%zu, c=%zu\n", a, b, c);

    updatePtrs(&a, &b, &c);
    printf("No restrict: a=%zu, b=%zu, c=%zu\n", a, b, c);

    a = 1, b = 2, c = 3;
    updatePtrs_restrict(&a, &b, &c);
    printf("Restrict:    a=%zu, b=%zu, c=%zu\n", a, b, c);

    return 0;
}
