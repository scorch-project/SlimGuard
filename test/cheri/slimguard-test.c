#include <slimguard.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int num = 1000;
    void *ptr[num];

    for (int i = 0; i < num; i++) {
    	int size = rand()%4096;
        ptr[i] = slimguard_malloc(size);
        assert(ptr[i]);
        memset(ptr[i], 0x0, size);
    }

    for (int i = (num-1); i >= 0; i--) {
        slimguard_free(ptr[i]);
    }
}
