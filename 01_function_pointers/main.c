#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


// A simple function
int foo(int x, int y) {
    return x + y;
}

// The predicate function we will pass in
bool p(int x) {
    return x % 2 == 0;
}

// A function that takes a function pointer 'predicate'
void print_if(int xs[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i++) {
        if (predicate(xs[i]))
            printf("%d\n", xs[i]);
    }
}

// Example compare function for real world qsort example
// Out function returns
//   -1 if it is before
//   +1 if it is after
int compar(const void *x1, const void *x2) {
    // The (*(int*)x) is a:
    //   convert *x into an int
    //   dereference the new int
    return (*(int*)x2) - (*(int*)x1);
}

// Making a type for a function pointer
typedef int (*t_my_func)(int, int);

int main(void) {
    int xs[] = {6, 3, 2, 4, 5, 1, 9, 8, 7, 10};

    // We can define a function pointer "f" and use it
    int (*f)(int, int) = foo;
    printf("Using our function pointer\n");
    printf("%d\n", f(3, 4));

    // Using function pointers is more useful when we pass
    // function pointers to other functions.
    printf("\nPassing a function pointer into a function\n");
    print_if(xs, p);

    // A real world example would be the qsort() function
    printf("\nReal world example: Passing a function into the qsort() function\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }
    // We pass our compar() function into qsort
    qsort(xs, 10, sizeof(int), compar);
    printf("--- qsort() ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", xs[i]);
    }

    // Using our type to get a function pointer
    t_my_func f_ptr = foo;
    printf("\nDeclaring a function pointer type\n");
    printf("%d\n", f_ptr(5, 5));

    return 0;
}
