#include <stdio.h>

int main(void) {
    int a = 42;
    const int *ptr_a = &a;

    ptr_a++;    // can modify the pointer itself
    //(*ptr_a)++; // cannot modify the value pointed to by the pointer

    int b = 42;
    int * const ptr_b = &b;

    //ptr_b++;      // cannot modify the pointer itself
    (*ptr_b)++;     // can modify the value that the pointer points to

    // const pointer to const int
    const int * const ptr = &a;
    // This cannot be modified in any way

    return 0;
}
