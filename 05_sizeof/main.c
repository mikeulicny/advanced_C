#include <stdio.h>

// Common macro you may see in a lot of C code
// Get the length of an array
// ! THIS CANNOT BE USED ON AN ARRAY POINTER !
#define ARRAY_LEN(a) (sizeof a / sizeof a[0])


int main() {
    int a = 1;
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *xs_ptr = xs;

    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(long));
    printf("%zu\n", sizeof a); // don't need parenthesis when using a variable
    printf("%zu\n", sizeof xs);
    printf("%zu\n", ARRAY_LEN(xs));
    printf("%zu\n", sizeof xs_ptr);

    return 0;
}
