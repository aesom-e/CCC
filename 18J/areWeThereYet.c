// 15/15
#include <stdio.h>

#define ushort unsigned short

ushort min(ushort a, ushort b) {
    if(a<b) return a;
    return b;
}

ushort max(ushort a, ushort b) {
    if(a<b) return b;
    return a;
}

ushort distance(ushort* cities, ushort cityOne, ushort cityTwo) {
    ushort count = 0, i;
    if(cityOne == cityTwo) return 0;
    for(i=min(cityOne, cityTwo);i<max(cityOne, cityTwo);i++) count += cities[i];
    return count;
}

int main() {
    ushort cities[5], i, j;
    scanf("%hd %hd %hd %hd", &cities[0], &cities[1], &cities[2], &cities[3]);
    for(i=0;i<5;i++) {
        for(j=0;j<4;j++) {
            printf("%hd ", distance(cities, i, j));
        }
        printf("%hd\n", distance(cities, i, 4));
    }
}
