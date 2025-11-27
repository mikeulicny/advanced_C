#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {

    char s[] = "1,2,3,4,5";
    char *token = strtok(s, ",");   // Provie the string, and the delimiter
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    // This can not handle empty fields. So "1,2,,3,,,4,5" will
    // only provide "1", "2", "3", "4", "5"

    // More sane way (this one can handle empty fields)
    char s2[] = "1,2,3,4,5";
    char *s_ptr = s2;
    char *token2;
    while ((token2 = strsep(&s_ptr, ",")) != NULL) {
        printf("%s\n", token2);
    }

    return 0;
}
