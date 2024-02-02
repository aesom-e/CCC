// 15/15
#include <stdio.h>

int max(int a, int b) { if(a>b) return a; return b; }

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int* list, int len) {
    int i, j, temp, swapped;
    for(i=0;i<len-1;i++) {
        swapped = 0;
        for(j=0;j<len-1;j++) {
            if(list[j] > list[j+1]) { swap(&list[j], &list[j+1]); swapped = 1; }
        }
        if(!swapped) break;
    }
}

void combineArrs(int* dest, const int* sourceOne, const int* sourceTwo, int sourceLen) {
    int i, saved;
    for(i=0;i<sourceLen;i++) {
        dest[i] = sourceOne[i];
    }
    saved = i;
    for(i=0;i<sourceLen;i++) {
        dest[i+saved] = sourceTwo[i];
    }
}

int main() {
    int gettingMax, amount, i, speedOne[100], speedTwo[100], speed = 0;
    scanf("%d", &gettingMax); gettingMax--;
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%d", &speedOne[i]);
    }
    for(i=0;i<amount;i++) {
        scanf("%d", &speedTwo[i]);
    }
    if(gettingMax) {
        int speeds[200];
        combineArrs(speeds, speedOne, speedTwo, amount);
        sort(speeds, amount*2);
        for(i=amount*2-1;i>amount-1;i--) speed += speeds[i];
    } else {
        sort(speedOne, amount);
        sort(speedTwo, amount);
        for(i=0;i<amount;i++) {
            speed += max(speedOne[i], speedTwo[i]);
        }
    }
    printf("%d", speed);
}
