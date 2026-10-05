#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int numSpecialEquivGroups(char** words, int wordsSize) {
    char** signatures = (char**)malloc(wordsSize * sizeof(char*));
    int uniqueCount = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        int evenCount[26] = {0};
        int oddCount[26] = {0};
        int len = strlen(words[i]);
        
        for (int j = 0; j < len; j++) {
            if (j % 2 == 0) {
                evenCount[words[i][j] - 'a']++;
            } else {
                oddCount[words[i][j] - 'a']++;
            }
        }
        
        char sig[105];
        int idx = 0;
        for (int k = 0; k < 26; k++) {
            idx += sprintf(sig + idx, "%d,", evenCount[k]);
        }
        for (int k = 0; k < 26; k++) {
            idx += sprintf(sig + idx, "%d,", oddCount[k]);
        }
        
        // Check if this signature is already in our unique list
        bool exists = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(signatures[j], sig) == 0) {
                exists = true;
                break;
            }
        }
        
        if (!exists) {
            signatures[uniqueCount] = strdup(sig);
            uniqueCount++;
        }
    }
    
    for (int i = 0; i < uniqueCount; i++) {
        free(signatures[i]);
    }
    free(signatures);
    
    return uniqueCount;
}
