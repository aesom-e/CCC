#include <stdio.h>

int isTelemarketer(const int* number) {
    if(number[0] >= 8
    && number[1] == number[2]
    && number[3] >= 8) return 1;
    return 0;
}

int main() {
    int line[4];
    scanf("%d\n%d\n%d\n%d", &line[0], &line[1], &line[2], &line[3]);
    if(isTelemarketer(line)) printf("ignore");
    else printf("answer");
}