#include <slimguard.h>
#include <assert.h>

#define ALLOC_SIZE  (5*1024*1024)

int main(void) {
    void *ptr = xxmalloc(ALLOC_SIZE);
    assert(ptr);
    memset(ptr, 0x0, ALLOC_SIZE);
    xxfree(ptr);
}
