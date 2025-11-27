#include <stdio.h>
#include <stdbool.h>

// Using a simple #define for the flags
typedef unsigned int t_flag;
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_C (1 << 2)


int f1(int x, t_flag flags) {
    if (flags & FLAG_A)
        x += x;
    if (flags & FLAG_B)
        x *= x;
    if (flags & FLAG_C)
        x = ~x;
    return x;
}


// Using enum to declare flags, prevents using macros
//   *There is a 64 flag maximum with this method*
typedef enum {
    FLAG_D = (1 << 0),
    FLAG_E = (1 << 1),
    FLAG_F = (1 << 2)

} t_flag2;

int f2(int x, t_flag2 flags) {
    if (flags & FLAG_D) {
        x += x;
        // This is how to "unset" a flag
        //   AND everything with NOT FLAG_D
        flags &= ~FLAG_D;
    }
    if (flags & FLAG_E)
        x *= x;
    if (flags & FLAG_F)
        x = ~x;
    return x;
}

int main(void) {

    printf("%d\n", f1(1234, 0));
    printf("%d\n", f1(1234, FLAG_A));
    printf("%d\n", f1(1234, FLAG_B | FLAG_C));

    printf("%d\n", f2(1234, 0));
    printf("%d\n", f2(1234, FLAG_D));
    printf("%d\n", f2(1234, FLAG_E | FLAG_F));

// Real world example
//
//  window = SDL_CreateWindow(
//      "title",
//      0, 0,
//      640, 1080,
//      SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN,
//  );

    return 0;
}
