#include <stdio.h>
#include <string.h>
#include <fnmatch.h>
#include <glob.h>

// fnmatch() takes
// - pattern
// - string to match the pattern on
// - flags

void example1() {
    char *s = "Hello, world!";
    int result = fnmatch("He???, world!", s, 0);
    if (result == 0)
        printf("match\n");
    else if (result == FNM_NOMATCH)
        printf("no match\n");
}

// Flags:
// - FNM_NOESCAPE: exact matching (no escape characters)
// - FNM_PATHNAME: proper matching functionality with '/' character
// - FNM_PERIOD: proper matching functionality with '.' character

void example2() {
    char *s = "path/to/.file";
    int result = fnmatch("path/*/.file", s, FNM_PATHNAME | FNM_PERIOD);
    if (result == 0)
        printf("Example 2: match\n");
    else if (result == FNM_NOMATCH)
        printf("Example 2: no match\n");

}

void example3() {
    // place to store a result of your match, of type glob_t
    glob_t pglob;
    int result = glob("*.c", 0, NULL, &pglob);
    // result:
    // 0 - success 
    // GLOB_NOMATCH
    // GLOB_ABORT
    // GLOB_NOSPACE

    // The 'NULL' is your error function you can hook in
    // error function has this signiture
    // int errfunc(const char *epath, int errno)

    for (size_t i = 0; i < pglob.gl_pathc; i++)
        printf("%zu: %s\n", i, pglob.gl_pathv[i]);
    globfree(&pglob);
}

int main(void) {

    example1();
    example2();
    example3();

    return 0;
}
