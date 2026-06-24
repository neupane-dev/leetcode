cmake_minimum_required(VERSION 3.10)
project(LeetCode_Solutions C)

set(CMAKE_C_STANDARD 11)
enable_testing()


# Problem 2: Add Two Numbers
add_executable(add_two_numbers_solution lc_2.c lc_2_test.c)
add_test(NAME TestAddTwoNumbers COMMAND add_two_numbers_solution)