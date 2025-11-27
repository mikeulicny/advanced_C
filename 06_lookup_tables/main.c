#include <stdio.h>

// This is typically referred to as "Designated Initializers"

// First example uses enum as our mapping
enum foo {
    foo_2 = 0,
    foo_3,
    foo_4
};

// We can initialize the squares like this, using any order we want
static int squares[] = {
    [foo_3] = 9,
    [foo_2] = 4,
    [foo_4] = 16
};

// We can also use whatever values we want, so long as it can be fit into an unsigned int
static char case_convert[] = {
    ['b'] = 'B',
    ['a'] = 'A',
    ['c'] = 'C'
};

// The only downside to this is we need to be careful if using bitflags, as these may explode
// the size of the array

// Real world example
static const char escape_lookup[] = {
    ['t'] = '\t',
    ['n'] = '\n',
    ['r'] = '\r',
    ['v'] = '\v',
    ['f'] = '\f',
};

// The chars could also map to structs, that contain functions that would need to be called
// depending on the lookup

int main() {
    printf("%d\n", squares[foo_2]);
    printf("%d\n", squares[foo_3]);
    printf("%d\n", squares[foo_4]);

    printf("%c\n", case_convert['a']);
    printf("%c\n", case_convert['b']);
    printf("%c\n", case_convert['c']);

    return 0;
}
