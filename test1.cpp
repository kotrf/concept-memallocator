#include "memallocator.h"

static char heapRgn0[MemAllocator::BlocksTotal * MemAllocator::BlockSize];

MemAllocator memory(heapRgn0);

int main()
{
    void *p0 = memory.malloc();
    void *p1 = memory.malloc();
    void *p2 = memory.malloc();
    void *p3 = memory.malloc();
    void *pFail = memory.malloc();

    if (p0 && p1 && p2 && p3 && !pFail)
        return 0;
    else
        return 1;
}
