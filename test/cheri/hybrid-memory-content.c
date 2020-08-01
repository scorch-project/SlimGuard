#include <assert.h>
#include <slimguard.h>
#include <cheri/cheric.h>

#define ALLOC_NUM   10000

int main(void) {
    uint64_t * __capability * __capability ptr = slimguard_hc_malloc(ALLOC_NUM * sizeof(uint64_t * __capability));
    assert(ptr);

    for(int i=0; i<ALLOC_NUM; i++) {
        ptr[i] = slimguard_hc_malloc(sizeof(uint64_t));
        assert(ptr[i]);
        *(ptr[i]) = 0xDEADBEEFDEADBEEF;
    }

    for(int i=0; i<ALLOC_NUM; i++) {
        assert(*(ptr[i]) == 0xDEADBEEFDEADBEEF);
        slimguard_hc_free(ptr[i]);
    }

    slimguard_hc_free(ptr);
}
