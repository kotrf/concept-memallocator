#include "memallocator.h"

static char heapRgn0[MemAllocator::BlocksTotal * MemAllocator::BlockSize];

MemAllocator memory(heapRgn0);

int main()
{
    void *p0 = memory.malloc();
    void *p1 = memory.malloc();
    void *p2 = memory.malloc();
    void *p3 = memory.malloc();

    if (!p0 || !p1 || !p2 || !p3)
        return 1;

    void *p4 = memory.malloc();
    if (p4)
        return 1;

    if (!memory.mfree(p3))
        return 1;

    p4 = memory.malloc();
    if (!p4)
        return 1;

    return 0;
}
