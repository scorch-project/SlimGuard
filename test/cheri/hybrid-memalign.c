#include "../../include/slimguard.h"
#include "../../include/slimguard-large.h"
#include "../../include/sll.h"
#include <cheri/cheric.h>

#include <assert.h>

#define MAX_ALIGNMENT   (1024*1024)
#define ITERATIONS      100
#define VERBOSE         0

int main(int argc, char **argv) {
    for(int alignment = 16; alignment<=MAX_ALIGNMENT; alignment*=2) {
        void * __capability ptrs[ITERATIONS];
        void * __capability ptrs2[ITERATIONS];
        void * __capability ptrs3[ITERATIONS];

        for(int i=0; i<ITERATIONS; i++) {
            ptrs[i] = slimguard_hc_memalign(alignment, alignment);
            assert(ptrs[i]);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs[i]);
#endif
            assert(!(__builtin_cheri_address_get(ptrs[i]) % alignment));
            memset_c(ptrs[i], 0x0, alignment);
        }

        for(int i=0; i<ITERATIONS; i++)
            slimguard_hc_free(ptrs[i]);

        for(int i=0; i<ITERATIONS; i++) {
            ptrs2[i] = slimguard_hc_memalign(alignment, alignment*2);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs2[i]);
#endif
            assert(ptrs2[i]);
            assert(!(__builtin_cheri_address_get(ptrs2[i]) % alignment));
            memset_c(ptrs2[i], 0x0, alignment*2);
        }

        for(int i=0; i<ITERATIONS; i++)
            slimguard_hc_free(ptrs2[i]);

        for(int i=0; i<ITERATIONS; i++) {
            ptrs3[i] = slimguard_hc_memalign(alignment, alignment/2);
#if VERBOSE == 1
            printf("Required alignment 0x%x got pointer @%p\n", alignment,
                    ptrs3[i]);
#endif
            assert(ptrs3[i]);
            assert(!(__builtin_cheri_address_get(ptrs3[i]) % alignment));
            memset_c(ptrs3[i], 0x0, alignment/2);
        }

        for(int i=0; i<ITERATIONS; i++)
            slimguard_hc_free(ptrs3[i]);

    }

}
