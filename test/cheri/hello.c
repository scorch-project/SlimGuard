#include <slimguard.h>
#include <assert.h>
#include <stdlib.h>

#define SIZE 64

int main(int argc, char **argv) {
        int *x = slimguard_malloc(SIZE);
        assert(x);
        memset(x, 0x0, SIZE);
        slimguard_free(x);
}
