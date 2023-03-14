#include <iostream>
#include <iomanip>
#include "memallocator.h"
#include "threadlock.h"

// Use in thread-safe env (define obj before any thread start)
MemAllocator::MemAllocator(char *heap)
    : heap(heap)
{
    for (int n = 0; n < BlocksTotal; ++n)
        usage[n] = false;
}

// Use in thread-safe env (delete obj after all threads stop)
MemAllocator::~MemAllocator()
{
    // clear heap if necessary
}

void *MemAllocator::malloc()
{
    ThreadLock lock; // lock thread, unlock at destruction of obj

    // Find free block. Slow but simple method
    int blockI = 0;
    while (blockI != BlocksTotal && usage[blockI])
        ++blockI;
    if (blockI == BlocksTotal)
        return nullptr; // no free blocks

    usage[blockI] = true;   // mark block as used
    return &heap[blockI * BlockSize];
}

bool MemAllocator::mfree(void *ptr)
{
    ThreadLock lock; // lock thread, unlock at destruction of obj

    int blockI = int(ptrdiff_t(ptr) - ptrdiff_t(heap)) / BlockSize;
    if (blockI >= 0 && blockI < BlocksTotal)
    {
        usage[blockI] = false;  // mark block as free
        return true;
    }

    return false;   // invalid ptr
}
