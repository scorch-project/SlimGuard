#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../../include/slimguard.h"

#define OLD_SIZE    128
#define NEW_SIZE    2048

#if OLD_SIZE > NEW_SIZE
#error "OLD_SIZE must be < NEW_SIZE"
#endif

int main(int argc, char **argv) {
    void *ptr = slimguard_malloc(OLD_SIZE);
    assert(ptr);
    memset(ptr, 0x0, OLD_SIZE);

    ptr = slimguard_realloc(ptr, NEW_SIZE);
    memset((char *)ptr + OLD_SIZE, 0x0, NEW_SIZE - OLD_SIZE);

    for(int i=0; i<NEW_SIZE; i++) {
        int val = *((char *)ptr+i);
        assert(val == 0);
    }

    slimguard_free(ptr);
}
