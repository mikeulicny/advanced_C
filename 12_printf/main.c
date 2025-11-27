#include <stdio.h>
#include <stddef.h>

int main(void) {
    int a = 1;

    // The '%d' here is referred to as a conversion, there are lots of them
    printf("%d\n", -32);        // decimal
    printf("%u\n", 32);         // unsigned
    printf("%f\n", 42.42);      // float (default: 6 precision)
    printf("%p\n", &a);         // pointer
    printf("%s\n", "Hello");    // string
    printf("%%\n");             // Print a '%' sign

    // If large will pick scientific notation, if smaller will use
    // regular floating point notation
    printf("%g\n", 12345678.123456789);
    printf("%g\n", 1.23);

    // Change the width
    printf("###%5d###\n", -32);   // Force 5 characters
    printf("###%05d###\n", -32);  // use '0' for padding with 5 characters
    printf("###% d###\n", -32);   // Leave 1 space for the sign (useful for aligning)
    printf("###% d###\n", 32);   // Leave 1 space for the sign (useful for aligning)
    printf("###%+d###\n", 32);   // Or use a '+' sign
    printf("###%-10d###\n", -32); // Left align with 10 spaces

    printf("%.2f\n", 1.234567891011); // Round to 2 decimal places
    
    printf("###%*d###\n", 10, -32);   // Take a width from the parameter, width = 10
    // Take a width from the first parameter and precision from the second
    printf("###%*.*f###\n", 10, 2, -32.12345678);   

    // Split by thousands for a human readable form
    // This is dependant on locale
    printf("%'f\n", 1234567.89);

    long int l = 100000000000000000;
    printf("%ld\n", l); // Handle long ints by putting 'l' between % and d
    long long int lli = l;
    printf("%lld\n", lli); // Long longs use two 'l's
    short s = 123;
    printf("%hd\n", s); // Shorts use an 'h'
    char c = 12;
    printf("%hhd\n", c); // Handle chars in decimal format

    // An unsigned int that can be 32 or 64 depending on platform
    // for this specific type the modifier is 'zu'
    size_t size = 256;
    printf("%zu\n", size);

    // Not everything is here!
    // Check out 'man printf 3'

    return 0;
}
