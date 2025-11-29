#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <bsd/bsd.h>
// BSD contains
// - mergesort
// - heapsort
#include <search.h>

#define ARRAY_LEN(arr) (sizeof (arr) / sizeof (arr)[0])

int compar_str(const void *v1, const void *v2) {
    char *s1 = *(char**)v1;
    char *s2 = *(char**)v2;
    return strcmp(s1, s2);
}

int compar_int(const void *v1, const void *v2) {
    int x1 = *(int*)v1;
    int x2 = *(int*)v2;
    return x1 - x2;
}

void example1() {
}

int main(void) {

    char *strings[] = {"hello", "bonjour", "ola", "hallo", "bom dia"};
    int xs[] = {1, 5, 2, 8, 7};

    for (int i = 0; i < ARRAY_LEN(strings); i++)
        printf("%d: %s\n", i, strings[i]);
    qsort(strings, ARRAY_LEN(strings), sizeof strings[0], compar_str);
    // Under the BSD library
    //mergesort(strings, ARRAY_LEN(strings), sizeof strings[0], compar_str);

    for (int i = 0; i < ARRAY_LEN(strings); i++)
        printf("%d: %s\n", i, strings[i]);

    for (int i = 0; i < ARRAY_LEN(xs); i++)
        printf("%d: %d\n", i, xs[i]);
    qsort(xs, ARRAY_LEN(xs), sizeof xs[0], compar_int);
    // Under the BSD library
    //mergesort(xs, ARRAY_LEN(xs), sizeof xs[0], compar_int);
    for (int i = 0; i < ARRAY_LEN(xs); i++)
        printf("%d: %d\n", i, xs[i]);

    // Binary search
    // *Must be sorted before using
    int needle = 7;
    void *result = bsearch(&needle, xs, ARRAY_LEN(xs), sizeof xs[0], compar_int);
    printf("%p: %d\n", result, *(int*)result);

    // Find search
    needle = 7;
    size_t len = ARRAY_LEN(xs); // lfind needs pointer instead of actual length
    result = lfind(&needle, xs, &len, sizeof xs[0], compar_int);
    printf("%p: %d\n", result, *(int*)result);

    // lsearch
    // same as find search, but if the element is not fount it is appended
    // to the array
    int ys[10] = {1, 5, 2, 8, 7};   // init array with extra space for lsearch
    needle = 542;
    len = 5; // lsearch needs pointer instead of actual length
    result = lsearch(&needle, ys, &len, sizeof ys[0], compar_int);
    for (int i = 0; i < ARRAY_LEN(ys); i++)
        printf("%d: %d\n", i, ys[i]);


    return 0;
}
