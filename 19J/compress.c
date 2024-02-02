#include <stdio.h>
#include <string.h>

int main() {
    int amount, i, j, len, count;
    char line[81], curChar;
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%s", line);
        len = strlen(line);
        count = 0;
        curChar = 0;
        for(j=0;j<len;j++) {
            if(count == 0) { curChar = line[j]; count++; continue; }
            if(curChar == line[j]) {
                count++;
                continue;
            }
            // curChar != line[j]
            printf("%d %c ", count, curChar);
            count = 1;
            curChar = line[j];
        }
        printf("%d %c\n", count, curChar);
    }
}