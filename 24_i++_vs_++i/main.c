#include <stdio.h>

int main(void) {
    // First way
    for (int i = 0; i < 10; i++)
        printf("%d\n", i);

    // Second way
    for (int i = 0; i < 10; ++i)
        printf("%d\n", i);
    

    int xs[] = {1, 2, 3, 4, 5, -1};
    int i = 0;
    while (xs[i] != -1) {
        // First way
        //int x = xs[i++];    // access the array, then increment i

        // Second way
        int x = xs[++i];    // first increment i, then access the array
        printf("%d\n", x);
        i++;
    }

    return 0;
}
