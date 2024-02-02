// 15/15
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int palindromeLen(char* word, int middle) {
    int len, i, extra = 0;
    for(i=1;middle+i<strlen(word)&&middle-i>=0;i++) {
        if(word[middle+i] != word[middle-i]) break;
    }
    len = i;
    // If middle+1 exists in the word
    if(strlen(word)-2>middle) {
        if(word[middle+1] == word[middle]) {
            for(i=1;middle+i+1<strlen(word)&&middle-i>=0;i++) {
                if(word[middle+i+1] != word[middle-i]) break;
            }
            len = max(len, i);
            extra = 1;
        }
    }
    return max(len*2-1+extra, 1);
}

int maxPalindromeLen(char* word) {
    int i, maxLen = 1;
    for(i=0;i<strlen(word);i++) maxLen = max(maxLen, palindromeLen(word, i));
    return maxLen;
}

int main() {
    char input[41];
    scanf("%s", input);
    printf("%d", maxPalindromeLen(input));
}
