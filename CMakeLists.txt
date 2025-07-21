cmake_minimum_required(VERSION 3.10)

project(VirtualMemory)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp)

# Add the main executable as a test
enable_testing()

math(EXPR size "1024 * 1024 * 512")  # ~512 million numbers = 2GB (for 4byte int) and 4GB (for 8byte int) 
add_test(NAME MainTest1 COMMAND main 1000000 ${size})
add_test(NAME MainTest2 COMMAND main 5000000 ${size})

math(EXPR big_size "1024 * 1024 * 1024")  # ~1 billion numbers  = $4B (for 4byte int) and 8GB (for 8byte int)

add_test(NAME MainTest3 COMMAND main 1000000 ${big_size})
add_test(NAME MainTest4 COMMAND main 5000000 ${big_size})
