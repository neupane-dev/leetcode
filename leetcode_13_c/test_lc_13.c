#include "lc_13.h"
#include <stdio.h>

#include <string.h>


#define ASSERT_ROMAN_TO_INT(input, expected,name)\
    do{\
        int res = romanToInt(input);\
        if(res == expected) \
        {\
            printf("[PASS] %s (Input: %s)\n",name,input);\
        }else {\
            printf("[FAIL] %s (Input: %s) | Expected %d, got %d\n",name,input,expected,res);\
            failed_tests++;\
        }\
    }while(0)

int main(void)
{
    int failed_tests = 0;

    printf("=========================================\n");
    printf("   RUNNING ROMAN_TO_IBT TEST SUITE       \n");
    printf("=========================================\n");

    ASSERT_ROMAN_TO_INT("III", 3, "Test Basic Addition");
    ASSERT_ROMAN_TO_INT("IV", 4, "Test Single Subtraction");
    ASSERT_ROMAN_TO_INT("LVIII", 58, "Test Complex Addition");
    ASSERT_ROMAN_TO_INT("MCMXCIV", 1994, "Test Complex Subtraction Mixture");
    ASSERT_ROMAN_TO_INT("MMXXVI", 2026, "Test Current Year");

    printf("===========================================\n");
    if (failed_tests == 0) {
        printf("ALL TESTS PASSED SUCCESSFULLY!\n");
    } else {
        printf("TEST SUITE FAILED: %d test(s) failed.\n", failed_tests);
    }
    printf("===========================================\n");

}