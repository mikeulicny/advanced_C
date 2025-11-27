#include <stdio.h>

// This will actually stringify the variable names of the
// parameters passed in
#define FOO(x, y) printf("%s + %s = %d\n", #x, #y, (x) + (y))

// Tokenize the argument of a macro
// This can be used to dynamically create a new variable or function name
#define PREFIX(var_name) new_##var_name

// This can be expaned to do generic style code
#define GENERIC_ADD_FUNC(type)          \
    type add_##type(type x, type y) {   \
        return x + y;                   \
    }
// Then define the function(s) in the global scope
GENERIC_ADD_FUNC(int)
GENERIC_ADD_FUNC(float)
GENERIC_ADD_FUNC(long)


int main(void) {

    int first = 123;
    int second = 456;

    FOO(first, second);

    int PREFIX(foo) = 123; // this created a new variable called 'new_foo'
    printf("%d\n", new_foo);
    
    // Once we declare our generic add function (in the global scope)
    // we can use it here
    printf("%d\n", add_int(1, 2));
    printf("%f\n", add_float(1.1234, 2.1234));
    printf("%ld\n", add_long(1L, 211092391023));

    return 0;
}
