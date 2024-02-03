#include <stdio.h>
#include <string.h>

int isValidChar(char in) {
    if(in == 'I' || in == 'O'
    || in == 'S' || in == 'H'
    || in == 'Z' || in == 'X'
    || in == 'N') return 1;
    return 0;
}

int isValid(char* in) {
    int i, len;
    len = strlen(in);
    for(i=0;i<len;i++) if(!isValidChar(in[i])) return 0;
    return 1;
}

int main() {
    char input[31];
    scanf("%s", input);
    if(isValid(input)) printf("YES");
    else printf("NO");
}