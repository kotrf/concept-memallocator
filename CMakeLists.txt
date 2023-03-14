cmake_minimum_required(VERSION 3.10)
project(MemAllocator VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(MEM_ALLOCATOR_BLOCK_SIZE=4096)
add_compile_definitions(MEM_ALLOCATOR_BLOCKS_TOTAL=4)

add_executable(main threadlock.cpp memallocator.cpp main.cpp)
add_executable(cpp_test0 threadlock.cpp memallocator.cpp test0.cpp)
add_executable(cpp_test1 threadlock.cpp memallocator.cpp test1.cpp)
add_executable(cpp_test2 threadlock.cpp memallocator.cpp test2.cpp)

enable_testing()
add_test(
  NAME cpp_test0
  COMMAND $<TARGET_FILE:cpp_test0>
  )
add_test(
  NAME cpp_test1
  COMMAND $<TARGET_FILE:cpp_test1>
  )
add_test(
  NAME cpp_test2
  COMMAND $<TARGET_FILE:cpp_test2>
  )
