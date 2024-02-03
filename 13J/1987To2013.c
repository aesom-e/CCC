#include <stdio.h>
#include <string.h>

int isDifferent(int in) {
    int i, j, len;
    char num[8];
    sprintf(num, "%d", in);
    len = strlen(num);
    for(i=0;i<len;i++) {
        for(j=0;j<len;j++) if(num[i] == num[j] && i != j) return 0;
    }
    return 1;
}

int main() {
    int year;
    scanf("%d", &year);
    while(!isDifferent(++year));
    printf("%d", year);
}