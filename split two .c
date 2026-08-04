#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool checkSplit(char* a, char* b, int n) {
    int left = 0;
    int right = n - 1;
    
    while (left < right && a[left] == b[right]) {
        left++;
        right--;
    }
    
    return isPalindrome(a, left, right) || isPalindrome(b, left, right);
}

bool checkPalindromeFormation(char* a, char* b) {
    int n = strlen(a); 
    
    
    return checkSplit(a, b, n) || checkSplit(b, a, n);
}