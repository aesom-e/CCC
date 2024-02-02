// 3/15 (N<=50 && T = 1)
#include <stdio.h>

int max(int a, int b) {
    if(a<b) return b;
    return a;
}

int main() {
    int n, amount, i, x, y;
    scanf("%d\n%d", &n, &amount);
    scanf("%d %d", &x, &y);
    if(max(x,y)-1>n-(max(x,y)))
        printf("%d", max(x, y) - 1);
    else
        printf("%d", n-(max(x,y)));
}
