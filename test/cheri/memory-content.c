#include <assert.h>
#include <slimguard.h>

#define ALLOC_NUM   10000

int main(void) {
    uint64_t **ptr = (uint64_t **)slimguard_malloc(ALLOC_NUM * sizeof(uint64_t *));
    assert(ptr);

    for(int i=0; i<ALLOC_NUM; i++) {
        ptr[i] = (uint64_t *)slimguard_malloc(sizeof(uint64_t));
        assert(ptr[i]);
        *(ptr[i]) = 0xDEADBEEFDEADBEEF;
    }

    for(int i=0; i<ALLOC_NUM; i++) {
        assert(*(ptr[i]) == 0xDEADBEEFDEADBEEF);
        slimguard_free(ptr[i]);
    }

    slimguard_free(ptr);
}
