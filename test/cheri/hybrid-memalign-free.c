#include <assert.h>
#include <slimguard.h>
#include <cheri/cheric.h>

int main(void) {
    void * __capability ptr = slimguard_hc_memalign(128, 128);
    assert(ptr);
    assert(!(__builtin_cheri_address_get(ptr) % 128));
    memset_c(ptr, 0x0, 128);
    slimguard_hc_free(ptr);
}
