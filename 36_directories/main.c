#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include <sys/types.h>
#include <dirent.h>

int main(void) {

    DIR *dir = opendir("foo");

    struct dirent *entry;
    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s, is_directory=%d\n", entry->d_name, entry->d_type & DT_DIR);
    }
    assert(errno == 0);

    rewinddir(dir); // put file pointer back at the start of the directory
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Other directory functions
    // telldir
    // seekdir
    // scandir

    closedir(dir);

    // scandir returns number of entries
    struct dirent **entries;
    int n = scandir("foo", &entries, NULL, alphasort);
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i, entries[i]->d_name);

    return 0;
}
