#include <assert.h>
#include <slimguard.h>

int main(void) {
    void *ptr = xxmemalign(128, 128);
    assert(ptr);
    assert(!((uint64_t)ptr % 128));
    memset(ptr, 0x0, 128);
    xxfree(ptr);
}
