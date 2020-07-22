## SlimGuard: A Secure and Memory-Efficient Heap Allocator

This is the CHERI version of SlimGuard. For now the way to integrate it in an
application is to recompile the application with SlimGuard sources after having
replaced the calls to the malloc family of function into their SlimGuard
equivalent: just prefix their name with `xx`, for example `malloc` becomes
`xxmalloc`. The function in question are `malloc`, `free`, `realloc`, `calloc`,
`memalign`.

See examples in `test/cheri`.

Original README below.

---

SlimGuard is a secure dynamic memory allocator whose design is driven by memory
efficiency. We redesign the security features of state-of-the-art allocators
with memory efficiency in mind. SlimGuard protects against widespread heap-related
attacks such as overflows, over-reads, double/invalid free, and use-after-free.
Among other features, SlimGuard uses an efficient fine-grain size classes indexing
mechanism and implements a novel dynamic canary scheme optimized for memory
overhead reduction.

#### Build SlimGuard

SlimGuard can be built on most modern Linux distributions and has been tested on
Ubuntu 18.04 and Debian 10.

To build SlimGuard, run ```make``` in ```/path/to/libSlimGuard```

To use SlimGuard, you can 
1. link __libSlimGuard__ to your executable

2. setting ```LD_PRELOAD``` as an enviromment variable using 
```bash
export LD_PRELOAD=/path/to/libSlimGuard.so
```

3. simply run as 
```
LD_PRELOAD=/path/to/libSlimGuard.so /your/app
```

#### Tests

For this use cmake:
```
mkdir build
cd build
cmake ..
make
make test
```
