#include <string.h>

char* longestPalindrome(char* s) 
{
    if (s == NULL || strlen(s) == 0) 
    {
        return "";
    }
    int start = 0;
    int maxLength = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) 
    {
        int left = i, right = i;
        while (left >= 0 && right < len && s[left] == s[right]) 
        {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && right < len && s[left] == s[right]) 
        {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    }
    s[start + maxLength] = '\0';    
    return &s[start];
}
