#include <stdio.h>

// This is very useful if we are trying to read from a binary source (or write to)

struct foo {
    int first_4 : 4;
    int next_4  : 4;
    int alone   : 1;
    int rest    : 7;
};

int main(void) {

    // We will get a size of 4 bytes
    // Our size can only be as small as the largest field type (int = 4 bytes)
    printf("%zu\n", sizeof(struct foo));

    // We can now use the fields as ints (if we stay within reason)
    struct foo f;
    f.first_4 = 2;
    f.next_4 = 4;
    f.alone = 0;
    f.rest = 6;

    // We can now directly read (or write) this struct to a file
    // int fd = open(...);
    // read(fd, f, sizeof f);

    // A real world example would be the IPV4 header format. We can pack all this
    // into a single struct. Another example is the BMP (Bitmap Image File) standard.
    return 0;
}
