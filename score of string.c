static int scoreOfString(char* s) {
    int ans=0;
    for(register int i=1; s[i]!='\0'; i++)
        ans+=abs(s[i]-s[i-1]);
    return ans;
}