#pragma GCC optimize("O3", "unroll-loops")
static char ** commonChars(char ** words, int wordsSize, int* returnSize){
    char freq[26], minFreq[26];
    memset(minFreq, 100, 26);
    for (register int i=0; i<wordsSize; i++){
        memset(freq, 0, sizeof(freq));
        for(register int j=0; words[i][j]!='\0'; j++) freq[words[i][j]-'a']++;
        for(register int j=0; j<26; j++)
            minFreq[j]=(minFreq[j]>freq[j])?freq[j]:minFreq[j];
    }
    int sz=0, k=0;
    for(register int i=0; i<26; i++) sz+=minFreq[i];
    *returnSize=sz;
    char** ans=malloc(sizeof(char*)*sz);
    for(register int i=0; i<26; i++){
        for(register int j=0; j<minFreq[i]; j++){
            ans[k]=malloc(2);
            ans[k][0]=i+'a';
            ans[k][1]='\0';
            k++;
        }
    }
    return ans;
}
