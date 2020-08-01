#include <slimguard.h>
#include <assert.h>
#include <cheri/cheric.h>

#define ALLOC_SIZE  (5*1024*1024)

int main(void) {
    void * __capability ptr = slimguard_hc_malloc(ALLOC_SIZE);
    assert(ptr);
    memset_c(ptr, 0x0, ALLOC_SIZE);
    slimguard_hc_free(ptr);
}
