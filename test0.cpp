#include "memallocator.h"

static char heapRgn0[MemAllocator::BlocksTotal * MemAllocator::BlockSize];

MemAllocator memory(heapRgn0);

int main()
{
    void *p = memory.malloc();
    if (!p)
        return 1;

    if ( !memory.mfree(p) )
        return 1;

    return 0;
}
