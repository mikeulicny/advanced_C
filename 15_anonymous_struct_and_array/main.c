#include <stdio.h>

// The official term for these arrays and structs are called
// 'compound literals'

struct Vec2 {
    int x;
    int y;
};

int scale_sum(int scalar, struct Vec2 v) {
    return scalar * v.x + scalar * v.y;
}

int sum(int xs[], int len) {
    int s = 0;
    for (int i = 0; i < len; i++)
        s += xs[i];
    return s;
}

int main(void) {

    // Don't need to create a struct, embed it directly into the function call
    int result = scale_sum(5, (struct Vec2){2, 3});
    printf("%d\n", result);

    // Do this with arrays also
    int s = sum((int[]){1, 2, 3, 4, 5, 6, 7}, 7);
    printf("%d\n", s);
    
    // Or just declare a variable
    struct Vec2 v = (struct Vec2){2, 3};
    int *xs = (int[]){1, 2, 3, 4, 5, 6, 7};

    return 0;
}
