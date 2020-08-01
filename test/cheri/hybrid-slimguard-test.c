#include <slimguard.h>
#include <assert.h>
#include <stdlib.h>
#include <cheri/cheric.h>

int main(int argc, char **argv) {
    int num = 1000;
    void * __capability ptr[num];

    for (int i = 0; i < num; i++) {
    	int size = rand()%4096;
        ptr[i] = slimguard_hc_malloc(size);
        assert(ptr[i]);
        memset_c(ptr[i], 0x0, size);
    }

    for (int i = (num-1); i >= 0; i--) {
        slimguard_hc_free(ptr[i]);
    }
}
