#include <stdio.h>

int main() {
    int count, a = 0, b = 0, i;
    char votes[16];
    scanf("%d\n%s", &count, votes);
    for(i=0;i<count;i++) {
        if(votes[i] == 'A') a++;
        else b++;
    }
    if(a > b) printf("A");
    else if(a < b) printf("B");
    else printf("Tie");
}