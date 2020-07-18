#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <slimguard.h>

#define NMEMB   10

int main(void) {

	for(int size = 16; size < (128*1024); size *= 2) {
	    void *ptr = xxcalloc(NMEMB, size);
	    assert(ptr);
	    memset(ptr, 0x0, size*NMEMB);
	    xxfree(ptr);
	}
}
