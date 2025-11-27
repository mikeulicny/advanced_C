#include <stdio.h>
#include <stdbool.h>

// A way to have dynamic typing in C
// This is not as clean, but still can be useful

enum tag {
    TAG_BOOL,
    TAG_INT,
    TAG_FLOAT
};

struct dynamic {
    enum tag tag;
    union {
        bool b;
        int i;
        float f;
    } value;        // In GCC we can remove this 'value' and then just call 'd.b' or 'd.i' below
};

int main(void) {

    struct dynamic d;
    // Using dynamic types in C can help greatly save on space
    // try changing the union to a struct
    printf("%zu\n", sizeof d);

    d.tag = TAG_INT;  // we can switch the tag
    d.value.i = 42;   // and the value

    // d.tag = TAG_FLOAT;
    // d.value.f = 42.42;

    switch (d.tag) {
    case TAG_BOOL: printf("%d\n", d.value.b); break;
    case TAG_INT: printf("%d\n", d.value.i); break;
    case TAG_FLOAT: printf("%f\n", d.value.f); break;
    }

    return 0;
}
