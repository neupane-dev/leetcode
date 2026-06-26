#include "lc_9.h"
#include <stdio.h>

bool isPalindrome(int x);

//Helper function for test reporting

#define ASSERT_PALINDROME(input, expected,name)\
    do{\
        bool res = isPalindrome(input);\
        if(res == expected) \
        {\
            printf("[PASS] %s (Input: %d)\n",name,input);\
        }else {\
            printf("[FAIL] %s (Input: %d) | Expected %s, got %s\n",name,input,expected?"true":"false",res?"true":"false");\
            failed_tests++;\
        }\
    }while(0)

int main(void) {
    int failed_tests = 0;

    printf("=========================================\n");
    printf("   RUNNING ISPALINDROME TEST SUITE       \n");
    printf("=========================================\n");

    // Category 1: Single Digits
    ASSERT_PALINDROME(0, true, "Zero base case");
    ASSERT_PALINDROME(5, true, "Single digit positive");

    // Category 2: Valid Palindromes
    ASSERT_PALINDROME(121, true, "Odd length palindrome");
    ASSERT_PALINDROME(8888, true, "Even length palindrome");
    ASSERT_PALINDROME(10001, true, "Multiple internal zeros");

    // Category 3: Non-Palindromes
    ASSERT_PALINDROME(123, false, "Standard sequential mismatch");
    ASSERT_PALINDROME(10, false, "Ends with zero");
    ASSERT_PALINDROME(12322, false, "Mismatch at the very end");

    // Category 4: Negative Numbers
    ASSERT_PALINDROME(-121, false, "Negative palindrome lookalike");
    ASSERT_PALINDROME(-7, false, "Negative single digit");

    // Category 5: Extremes / Large Numbers
    ASSERT_PALINDROME(2147447412, true, "Max-range 10-digit palindrome");
    ASSERT_PALINDROME(2147483647, false, "INT_MAX boundary");

    printf("=========================================\n");
    if (failed_tests == 0) {
        printf(" SUCCESS: All tests passed!\n");
    } else {
        printf(" FAILURE: %d test(s) failed.\n", failed_tests);
    }
    printf("=========================================\n");

    return failed_tests == 0 ? 0 : 1;
}