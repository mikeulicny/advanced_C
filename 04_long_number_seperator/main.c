#include <stdio.h>

// You can use a single quote to seperate digits in large numbers
// This C file must be compiled with the following
//   gcc -std=c2x main.c

int main(void) {

    int x = 1'000'000;
    printf("%d\n", x);

    return 0;
}
