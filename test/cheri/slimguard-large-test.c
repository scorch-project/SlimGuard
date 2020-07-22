#include <assert.h>
#include <slimguard.h>
#include <slimguard-large.h>

int main(void) {
    uint8_t iter = 100;
    void *p[iter];

    for (uint32_t i = 0; i < iter; i++) {
        p[i] = xxmalloc_large(1<<20, 0);
        assert(p[i]);
        memset(p[i], 0x0, 1<<20);
    }


    for (uint32_t i = 0; i < iter; i++) {
        assert(in_list(p[i]));
        //assert(((large_obj_t *)p[i])->align_size == (1<<20));
        if(xxfree_large(p[i]) == -1){
            printf("error %d %p\n", i, p[i]);
        }
    }

}

