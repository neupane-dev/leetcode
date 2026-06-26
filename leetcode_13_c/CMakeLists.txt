cmake_minimum_required(VERSION 3.10)

# Define project name and language
project(LeetCode13_RomanToInteger C)

# Set standard compiler flags (highly recommended for C code verification)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable testing framework support built into CMake
enable_testing()

# Create the test runner executable from your source files
add_executable(test_runner 
    lc_13.h 
    lc_13.c 
    test_lc_13.c
)

# Register the executable as a discoverable test for ctest
add_test(NAME RunRomanToIntegerTests COMMAND test_runner)