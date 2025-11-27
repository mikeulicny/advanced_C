#include <stddef.h>
#include <stdint.h>
#include <stdio.h>


// Very simple re-implementation of memset function
void *my_memset(void *data, uint8_t c, size_t n) {
    uint8_t *data_as_bytes = (uint8_t*)data;
    for (size_t i = 0; i < n; i++)
        data_as_bytes[i] = c;
    return data;
}

// More advanced example
// Out map takes:
//   xs:   an array (not enforced at compile time)
//   n:    length of this array
//   size: size of each element
//   *f:   function to apply to each element
void map(void *xs, size_t n, size_t size, void (*f)(void*)) {
    uint8_t *xs_as_bytes = (uint8_t*)xs; // convert to bytes (easier)
    for (size_t i = 0; i < n; i++)
        f(&xs_as_bytes[i * size]);       // shift by size of element on each iteration
}

void square(void *x) {
    int *p = x;
    *p = *p * *p;
}

int main(void) {

    // Very basic example
    int a = 3;
    void *p = &a; // void pointer to address of 'a'

    printf("Print the address of 'a'\n");
    printf("%p\n\n", p);
    // The compiler does not know the data type of the pointer,
    // so we must provide the datatype (int*), and then dereference it
    printf("Print the value of 'a'\n");
    printf("%d\n\n", *(int*)p);

    
    // Void pointers become much more useful when mixed with functions
    printf("Print the values in xs[] before and after my_memset()\n");
    int xs[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n");
    my_memset(xs, 0, sizeof xs);
    for (int i = 0; i < 5; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n");

    // More advanced real world example
    printf("Print the values in xa[] before and after map() with square\n");
    int xa[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", xa[i]);
    }
    printf("\n");
    map(xa, 5, sizeof(int), square);
    for (int i = 0; i < 5; i++) {
        printf("%d ", xa[i]);
    }
    printf("\n");

    return 0;
}

