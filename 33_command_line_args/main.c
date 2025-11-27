#include <stdio.h>
#include <unistd.h> // POSIX standard, great for simple tasks and what is shown here

// 'man 3 getopt'   not portable to windows

int main(int argc, char **argv) {

    int option; // option is always an int
    while ((option = getopt(argc, argv, ":a:b")) != -1) {    // syntax ':' passes in arg for flag a
                                                             // ':' as first character for error handling
                                                             // additional syntax available
        switch(option) {
            case 'a':
                printf("I got a: %s\n", optarg);    // variable optarg access this flag variable
                break;
            case 'b':
                printf("I got b\n");
                break;
            case '?': // this will override the default error message
                printf("ERROR\n");
                break;
            case ':': // will catch failure to pass argument to flags
                printf("expected argument\n");
                break;
        }
    }
    // Access args after flags like this
    for (int i = optind; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);

    // The 'stop parsing' with '--' works with this as well

    // See 'man getopt_long' which is GNU standard for command argument
    // Also see the <argp.h> header which is the advanced GNU library for complex tasks
    return 0;
}
