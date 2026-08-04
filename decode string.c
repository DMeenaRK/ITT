char* decodeString(char* s) {
    int len = strlen(s);
    
    int capacity = 10000;
    char *res = malloc(capacity * sizeof(char));
    res[0] = '\0';
    int res_len = 0;
    
    int countStack[1000];
    int countTop = -1;
    
    int indexStack[1000];
    int indexTop = -1;
    
    int i = 0;
    while (i < len) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            countStack[++countTop] = num;
        } 
      
        else if (s[i] == '[') {
            indexStack[++indexTop] = res_len;
            i++;
        } 
        else if (s[i] == ']') {
            int start_idx = indexStack[indexTop--];
            int repeat_count = countStack[countTop--];
            
            int sub_len = res_len - start_idx;
            char *sub = malloc((sub_len + 1) * sizeof(char));
            strncpy(sub, &res[start_idx], sub_len);
            sub[sub_len] = '\0';
            
            while (res_len + (sub_len * (repeat_count - 1)) >= capacity) {
                capacity *= 2;
                res = realloc(res, capacity * sizeof(char));
            }
            
            for (int c = 0; c < repeat_count - 1; c++) {
                strcpy(&res[res_len], sub);
                res_len += sub_len;
            }
            
            free(sub);
            i++;
        } 
       
        else {
            if (res_len + 1 >= capacity) {
                capacity *= 2;
                res = realloc(res, capacity * sizeof(char));
            }
            res[res_len++] = s[i++];
            res[res_len] = '\0';
        }
    }
    
    return res;
}