#include <stdbool.h>
#include <string.h>

bool digitCount(char* num) {
    int counts[10] = {0};
    int n = strlen(num);
    for (int i = 0; i < n; i++) {
        int digit = num[i] - '0';
        counts[digit]++;
    }
    
    for (int i = 0; i < n; i++) {
        int expected_count = num[i] - '0';
        int actual_count = counts[i];
        
        if (actual_count != expected_count) {
            return false;
        }
    }
    
    return true;
}]