#include <stdio.h>

// The __VA_ARGS__ grabs the arguments passed by the ...
#define PRINTF_LOOP(iterations, ...) do {   \
    for (int i = 0; i < (iterations); i++)  \
        printf(__VA_ARGS__);                \
} while (0)

int main(void) {

    PRINTF_LOOP(3, "Hello! %d %s\n", 32, "bar");
    return 0;
}
