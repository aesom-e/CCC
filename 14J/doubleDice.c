// 15/15
#include <stdio.h>

int main() {
    int count, i, playerOne = 100, playerTwo = 100, rollOne, rollTwo;
    scanf("%d", &count);
    for(i=0;i<count;i++) {
        scanf("%d %d", &rollOne, &rollTwo);
        if(rollOne > rollTwo) playerTwo -= rollOne;
        if(rollOne < rollTwo) playerOne -= rollTwo;
    }
    printf("%d\n%d", playerOne, playerTwo);
}
