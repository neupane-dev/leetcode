cmake_minimum_required(VERSION 3.10)
project(LeetCode_TwoSum C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Enable CMake's built-in testing features
# enable_testing()

# 2. Define the executable
add_executable(solution lc_1.c )

# 3. Register your executable as an official test case
# add_test(NAME RunTwoSumTests COMMAND solution)