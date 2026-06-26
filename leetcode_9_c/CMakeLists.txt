cmake_minimum_required(VERSION 3.10)
project(LeetCode_Solutions C)

set(CMAKE_C_STANDARD 11)
enable_testing()


# Problem 2: Add Two Numbers
add_executable(palindrome_number lc_9.c lc_9_test.c)
add_test(NAME TestPalindrome COMMAND palindrome_number)