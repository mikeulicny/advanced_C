#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

// errno is a global value that is set to the last error producted
// the errno needs to be manually reset to 0 before it will be used
// see 'man errno'
// call 'errno --list' to see all the variables
// different libraries will most likely have different error handling
// as errno is very specific to just C


int main(void) {
    
    FILE *f = fopen("main.c", "r"); // if there is an error, f will be NULL. Try changing the file name to cause errors
    if (f == NULL) {
        printf("%d\n", errno);
        perror(NULL);           // print the error message associated with the errno code
        perror("ERROR: ");      // A string can be passed in to prefix the error
        printf("%d: %s\n", errno, strerror(errno));  // You can also use strerror(errno) to show the error message
        return 1;
    }

    char c;
    while ((c = fgetc(f)) != EOF)
        fputc(c, stdout);

    return 0;
}
