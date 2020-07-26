#CC=cheribsd128n64-clang
CC=cheribsd128purecap-clang
CFLAGS=-I../../include -g -O0 -DRELEASE_MEM -DGUARDPAGE -DUSE_CANARY
SLIMGUARD=../../src/slimguard.c ../../src/slimguard-large.c ../../src/slimguard-mmap.c ../../src/sll.c
EXE=calloc memalign-free mimalloc-test sll-test large-alloc memalign \
	slimguard-large-test malloc-test memory-content slimguard-test \
	realloc
LDFLAGS=-lpthread

all: $(EXE)

.SUFFIXES:

$(EXE): % : %.c
	$(CC) $(CFLAGS) -o $@ $^ $(SLIMGUARD) $(LDFLAGS)

test: $(EXE)
	$(foreach exe, $(EXE), scp -P 18999 $(exe) localhost:~ && ssh -p 18999 localhost ./$(exe);)

clean:
	rm -rf *.o $(EXE)
