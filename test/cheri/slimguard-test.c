#include <slimguard.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int num = 1000;
    void *ptr[num];

    printf("starting %s\n", argv[0]);

    for (int i = 0; i < num; i++) {
    	int size = rand()%4096;
        ptr[i] = xxmalloc(size);
        assert(ptr[i]);
        memset(ptr[i], 0x0, size);
    }

    for (int i = (num-1); i >= 0; i--) {
        xxfree(ptr[i]);
    }
}
