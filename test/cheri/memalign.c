#include "../../include/slimguard.h"
#include "../../include/slimguard-large.h"
#include "../../include/sll.h"

#include <assert.h>

#define MAX_ALIGNMENT   (1024*1024)
#define ITERATIONS      100
#define VERBOSE         0

int main(int argc, char **argv) {
    for(int alignment = 16; alignment<=MAX_ALIGNMENT; alignment*=2) {
        void *ptrs[ITERATIONS];
        void *ptrs2[ITERATIONS];
        void *ptrs3[ITERATIONS];

        for(int i=0; i<ITERATIONS; i++) {
            ptrs[i] = xxmemalign(alignment, alignment);
            assert(ptrs[i]);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs[i]);
#endif
            assert(!((uint64_t)ptrs[i] % alignment));
            memset(ptrs[i], 0x0, alignment);
        }

        for(int i=0; i<ITERATIONS; i++)
            xxfree(ptrs[i]);

        for(int i=0; i<ITERATIONS; i++) {
            ptrs2[i] = xxmemalign(alignment, alignment*2);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs2[i]);
#endif
            assert(ptrs2[i]);
            assert(!((uint64_t)ptrs2[i] % alignment));
            memset(ptrs2[i], 0x0, alignment*2);
        }

        for(int i=0; i<ITERATIONS; i++)
            xxfree(ptrs2[i]);

        for(int i=0; i<ITERATIONS; i++) {
            ptrs3[i] = xxmemalign(alignment, alignment/2);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs3[i]);
#endif
            assert(ptrs3[i]);
            assert(!((uint64_t)ptrs3[i] % alignment));
            memset(ptrs3[i], 0x0, alignment/2);
        }

        for(int i=0; i<ITERATIONS; i++)
            xxfree(ptrs3[i]);

    }

}
