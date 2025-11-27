#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <regex.h>

// See 'man regex 3' for more details

void example1() {
    regex_t preg;
    assert(regcomp(&preg, "ab*", 0) == 0);    // compile your regex string to a pointer
                                              // * Note: This uses the old POSIX regex syntax, so double backslashes before groups
                                              // You can use the REG_EXTENDED flag here to use new syntax

    int result = regexec(&preg, "abb", 0, NULL, 0); // execute your compiled regex to an input string
    if (result == 0)
        printf("match\n");
    else if (result == REG_NOMATCH)
        printf("no match\n");

    regfree(&preg); // free the regex pointer
}

void example2() {
    // The regex_t struct only holds the exclusive indicies of the first and last characters in the matched string
    regex_t preg;
    assert(regcomp(&preg, "(ab*)(cd*)", REG_EXTENDED) == 0);

    const size_t nmatch = 10;       // number of "match on" we can store
    regmatch_t pmatch[nmatch + 1];  // array where we want to store the beginning and end of matching groups
    char *s = "abbcddddd";
    int result = regexec(&preg, s, nmatch, pmatch, 0);
    if (result == 0) {
        printf("match\n");
        for (size_t i = 0; pmatch[i].rm_so != -1 && i < nmatch; i++) {
            char buf[256] = {0};
            strncpy(buf, s + pmatch[i].rm_so, pmatch[i].rm_eo - pmatch[i].rm_so);
            printf("start %d, end %d: %s\n", pmatch[i].rm_so, pmatch[i].rm_eo, buf);
        }
    } else if (result == REG_NOMATCH)
        printf("no match\n");

    regfree(&preg);

}

void example3() {
    regex_t preg;
    int errcode = regcomp(&preg, "ab***", 0);
    if (errcode != 0) {
        const size_t errbuf_size = 129;
        char errbuf[errbuf_size + 2];
        regerror(errcode, &preg, errbuf, errbuf_size);
        printf("regex error '%s': %s", "ab***", errbuf);
    }
}

int main(void) {

    example1();
    example2();
    example3();

    return 0;
}

