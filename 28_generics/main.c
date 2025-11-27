#include <stdio.h>

int add_int(int a, int b) { return a + b; }
float add_float(float a, float b) { return a + b; }
double add_double(double a, double b) { return a + b; }

// use the '_Generic' special keyword, which will take a type and the functions to match
// the types on. You can also have a default case
#define add(a, b) _Generic((a),    \
    int    : add_int((a), (b)),    \
    float  : add_float((a), (b)),  \
    double : add_double((a), (b)), \
    default : printf("Don't know this type\n") \
)

int main(void) {

    int    ai = 1,    bi = 2;
    float  af = 1.12, bf = 2.32;
    double ad = 1.34, bd = 2.64;

    printf("add_int(ai, bi)    = %d\n", add_int(ai, bi));
    printf("add_float(af, bf)  = %f\n", add_float(af, bf));
    printf("add_double(ad, bd) = %f\n", add_double(ad, bd));

    printf("\n");
    printf("add(ai, bi) = %d\n", add(ai, bi));
    printf("add(af, bf) = %f\n", add(af, bf));
    printf("add(ad, bd) = %f\n", add(ad, bd));

    short a = 1, b = 2;
    add(a, b);

    return 0;
}
