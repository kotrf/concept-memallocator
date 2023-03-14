#ifndef __MEM_ALLOCATOR_
#define __MEM_ALLOCATOR_

#include <cstddef>

class MemAllocator {
public:
    static constexpr int BlockSize = MEM_ALLOCATOR_BLOCK_SIZE;
    static constexpr int BlocksTotal = MEM_ALLOCATOR_BLOCKS_TOTAL;

private:
    char *heap; // heap ptr
    bool usage[BlocksTotal]; // blocks usage  flags

public:
    MemAllocator(char *heap);
    ~MemAllocator();
    void *malloc();
    bool mfree(void *ptr);
};

#endif // __MEM_ALLOCATOR_
