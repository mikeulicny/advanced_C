#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

// Read a file line-by-line using the getline function

int main(void) {
    FILE *file = fopen("foo.txt", "r");
    assert(file != NULL);

    char *line = NULL;
    // char *line = malloc(sizeof(char) * 2048);   // You can manually allocate yourself instead
    size_t line_buf_len = 0;                       // change this to 2048 also if manually allocating
    ssize_t read_size = 0;

    // The line buffer length is being allocated and handled for us
    while (getline(&line, &line_buf_len, file) != -1) {
        line[read_size - 1] = '\0';
        printf("Malloc size: %zu - Line: %s\n", malloc_usable_size(line), line);
    }

    free(line);
    assert(feof(file));
    fclose(file);
    return 0;
}
