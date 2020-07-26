#include <assert.h>
#include <slimguard.h>
#include <slimguard-large.h>

int main(void) {
    uint8_t iter = 100;
    void *p[iter];

    for (uint32_t i = 0; i < iter; i++) {
        p[i] = slimguard_malloc(1<<20);
        assert(p[i]);
        memset(p[i], 0x0, 1<<20);
    }


    for (uint32_t i = 0; i < iter; i++) {
        assert(in_list(p[i]));
        //assert(((large_obj_t *)p[i])->align_size == (1<<20));
       slimguard_free(p[i]);
    }

}

