#include <slimguard.h>
#include <assert.h>
#include <stdlib.h>
#include <cheri/cheric.h>

#define SIZE 64

int main(int argc, char **argv) {
        int * __capability x = slimguard_hc_malloc(SIZE);
        assert(x);
        memset_c(x, 0x0, SIZE);
        slimguard_hc_free(x);
        printf("yeaaaaah\n");
}
