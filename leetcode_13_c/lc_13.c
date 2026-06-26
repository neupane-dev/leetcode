#include "lc_13.h"
#include <string.h>

// Helper function to get the integer value of a Roman numeral
static int getRomanValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanToInt(char* s) {
    if (s == NULL) return 0;
    
    int total = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        int current_val = getRomanValue(s[i]);
        
        // If the current value is less than the next value, subtract it
        if (i < n - 1 && current_val < getRomanValue(s[i + 1])) {
            total -= current_val;
        } else {
            total += current_val;
        }
    }
    
    return total;
}