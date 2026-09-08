#include <string.h>
void reverseRange(char* s, int left, int right)
{
    while (left < right) 
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
char* reverseWords(char* s) {
    int len = strlen(s);
    int writeIdx = 0;
    
    for (int i = 0; i < len; i++) 
    {
        if (s[i] != ' ') 
        {
            if (writeIdx > 0) 
            {
                s[writeIdx++] = ' ';
            }
            while (i < len && s[i] != ' ') 
            {
                s[writeIdx++] = s[i++];
            }
        }
    }
    s[writeIdx] = '\0';
    int cleanLen = writeIdx;
    
    reverseRange(s, 0, cleanLen - 1);
    int start = 0;
    for (int end = 0; end <= cleanLen; end++) 
    {
        if (s[end] == ' ' || s[end] == '\0') 
        {
            reverseRange(s, start, end - 1);
            start = end + 1;
        }
    }
    return s;
}
