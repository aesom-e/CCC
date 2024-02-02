// 15/15
#include <stdio.h>

int main() {
    int r = 0, s = 0;
    scanf("%d\n%d", &r, &s);
    int c = ((r * 8) + (s * 3)) - 28;
    if(c <= 0) printf("0");
    else printf("%d", c);
}
