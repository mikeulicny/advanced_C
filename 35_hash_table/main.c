#include <stdio.h>
#include <search.h>

void print_entry(ENTRY* entry) {
    if (entry == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%s -> %d\n", entry->key, entry->data);
}

int main(void) {

    // Hash table is implicit
    hcreate(30);

    ENTRY entry = { .key = "hello", .data = (void*)1 };
    // Insert data into the hash table
    ENTRY *result = hsearch(entry, ENTER);
    print_entry(result);

    result = hsearch(entry, FIND);
    print_entry(result);

    hdestroy();
    return 0;
}
