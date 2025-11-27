#include <stdio.h>

// In macro functions we should always do the following
// - Wrap the entire function in parenthesis
// - Wrap every variable in parenthesis
#define ADD(x, y) ((x) + (y))

// Multiline macros
// - Need to scope the macro with a do while that does not loop
#define SUM_RANGE(start, end) do {          \
    int sum = 0;                            \
    for (int x = (start); x < (end); x++)   \
        sum += x;                           \
    printf("sum: %d\n", sum);               \
} while (0)

int main(void) {
    
    int sum = 20;
    int x = 5 * ADD(2, 3);
    printf("%d\n", x);

    SUM_RANGE(2, 10);

    return 0;
}
