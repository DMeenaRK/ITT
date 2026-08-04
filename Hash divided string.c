char* stringHash(char* s, int k) {
    char*ans=(char*)malloc(2000*sizeof(char));
    int x=0,n,i,s1=0,m=0;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        s1=s1+(s[i]-'a');
        x++;
        if(x==k) 
       {
         s1=s1%26;
         ans[m++]=97+s1;
         x=0;
         s1=0;
       }
    }
    ans[m]='\0';
    return ans;
}
