#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The important thing is where these live in memory. We can modify an array as shown below.

// You can use 'objdump -s -j .rodata a.out' to show the string literal is in read-only memory.

int main(void) {
    char *literal = "I am a string literal";
    char array[] = "I am a string array";

    array[0] = '#';
    // literal[0] = '#'; // This will NOT throw a compile error, but it WILL SEGFAULT!

    printf("%s\n", literal);
    printf("%s\n", array);

    // We have to copy, then modify the literal. This copy is now on the heap.
    char *s = strdup(literal);
    s[0] = '#';
    printf("%s\n", s);

    return 0;
}
