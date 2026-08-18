#include <stdbool.h>
#include <string.h>
bool isIsomorphic(char* s, char* t) 
{
    int mapS[256] = {0};
    int mapT[256] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++)
     {
        unsigned char c1 = s[i];
        unsigned char c2 = t[i];
        if (mapS[c1] != mapT[c2]) 
        {
            return false;
        }   
        mapS[c1] = i + 1;
        mapT[c2] = i + 1;
    }
    return true;
}
