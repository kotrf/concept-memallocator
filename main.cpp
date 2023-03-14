#include <iostream>
#include "memallocator.h"

static char heapRgn0[MemAllocator::BlocksTotal * MemAllocator::BlockSize];

MemAllocator memory(heapRgn0);

int main()
{
    std::cout << "heapRgn0: " << reinterpret_cast<void *>(heapRgn0) << std::endl;

    void *p0 = memory.malloc();
    void *p1 = memory.malloc();
    void *p2 = memory.malloc();
    void *p3 = memory.malloc();
    void *p4 = memory.malloc();

    std::cout << "p0: " <<  (void *)p0 << std::endl;
    std::cout << "p1: " <<  (void *)p1 << std::endl;
    std::cout << "p2: " <<  (void *)p2 << std::endl;
    std::cout << "p3: " <<  (void *)p3 << std::endl;

    if ( p4 )
        std::cout << "p4: " <<  (void *)p3 << std::endl;
    else
        std::cout << "p4: unable allocate memory block\n";

    std::cout << "free(p0): " << (memory.mfree(p0) ? "done" : "fail") << std::endl;
    std::cout << "free(p1): " << (memory.mfree(p1) ? "done" : "fail") << std::endl;
    std::cout << "free(p2): " << (memory.mfree(p2) ? "done" : "fail") << std::endl;
    std::cout << "free(p3): " << (memory.mfree(p3) ? "done" : "fail") << std::endl;
    std::cout << "free(p4): " << (memory.mfree(p4) ? "done" : "fail") << std::endl;

    return 0;
}
