#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <slimguard.h>
#include <cheri/cheric.h>

#define NMEMB   10

int main(void) {

	for(int size = 16; size < (128*1024); size *= 2) {
	    void * __capability ptr = slimguard_hc_calloc(NMEMB, size);
	    assert(ptr);
	    memset_c(ptr, 0x0, size*NMEMB);
	    slimguard_hc_free(ptr);
	}
}
