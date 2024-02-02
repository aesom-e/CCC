#include <stdio.h>
#include <stdlib.h>

int main() {
    int amount, i, count = 0;
    scanf("%d", &amount);
    char* lineOne = (char*)malloc(sizeof(char)*(amount+1));
    char* lineTwo = (char*)malloc(sizeof(char)*(amount+1));
    scanf("%s\n%s", lineOne, lineTwo);
    for(i=0;i<amount;i++) {
        if(lineOne[i] == 'C'
        && lineTwo[i] == 'C') count++;
    }
    printf("%d", count);
}