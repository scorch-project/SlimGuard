# purecap or hybrid
ABI=purecap

CFLAGS=-I../../include -g -O0 -DRELEASE_MEM -DUSE_CANARY -DDESTROY_ON_FREE -DGUARDPAGE
SLIMGUARD=../../src/slimguard.c ../../src/slimguard-large.c ../../src/slimguard-mmap.c ../../src/sll.c

ifeq ($(ABI),purecap)
    CC=cheribsd128purecap-clang
else
    CC=cheribsd128n64-clang
endif

EXE=calloc memalign-free mimalloc-test sll-test large-alloc memalign \
	slimguard-large-test malloc-test memory-content slimguard-test \
	realloc
HYBRID_EXE= hybrid-slimguard-test hybrid-calloc hybrid-large-alloc \
    hybrid-memalign-free hybrid-memalign hybrid-memory-content \
    hybrid-mimalloc-test hybrid-malloc-test

LDFLAGS=-lpthread

ifeq ($(ABI),hybrid)
EXE+= $(HYBRID_EXE)
endif

all: $(EXE)

.SUFFIXES:

$(EXE): % : %.c $(SLIMGUARD)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test: $(EXE)
	$(foreach exe, $(EXE), scp -P 18999 $(exe) localhost:~ && ssh -p 18999 localhost ./$(exe);)

clean:
	rm -rf *.o $(EXE) $(HYBRID_EXE)
