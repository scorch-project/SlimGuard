#include <stdio.h>
#include <slimguard.h>
#include <assert.h>

#define MAX_ALIGNMENT   (1024*1024)

int main(void) {
    for(int alignment = 16; alignment<=MAX_ALIGNMENT; alignment*=2) {

        void *ptr = xxmemalign(alignment, alignment);
        assert(ptr);
        printf("Required alignment 0x%x got pointer @%p\n", alignment, ptr);
        assert(!((uint64_t)ptr % alignment));
        memset(ptr, 0x0, alignment);
        xxfree(ptr);

        void *ptr2 = xxmemalign(alignment, alignment*2);
        printf("Required alignment 0x%x got pointer @%p\n", alignment, ptr2);
        assert(ptr2);
        assert(!((uint64_t)ptr2 % alignment));
        memset(ptr2, 0x0, alignment*2);
        xxfree(ptr2);

        void *ptr3 = xxmemalign(alignment, alignment/2);
        printf("Required alignment 0x%x got pointer @%p\n", alignment, ptr3);
        assert(ptr3);
        assert(!((uint64_t)ptr3 % alignment));
        memset(ptr3, 0x0, alignment/2);
        xxfree(ptr3);
    }

}
