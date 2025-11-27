#include <stdio.h>
#include <stdarg.h>

// Some examples of functions that use this in the wild
//   printf()
//   execl()
//   open()

// This function uses the stdarg library to handle variable arguments
int sum_all(int count, ...) {
    va_list ap; // argument pointer
    va_start(ap, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        int x = va_arg(ap, int);    // We give it the argument pointer and the type
        sum += x;
    }
    va_end(ap);
    return sum;
}

int main(void) {

    printf("%d\n", sum_all(3, 5, 6, 7));

    return 0;
}
