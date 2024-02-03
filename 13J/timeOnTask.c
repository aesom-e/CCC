#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int* list, int len) {
    int i, j, swapped = 0;
    for(i=0;i<len-1;i++) {
        swapped = 0;
        for(j=0;j<len-1;j++) {
            if(list[j] > list[j+1]) { swap(&list[j], &list[j+1]); swapped = 1; }
        }
        if(!swapped) return;
    }
}

int main() {
    int mins, choresNum, chores[100], i, count = 0, countMins = 0;
    scanf("%d\n%d", &mins, &choresNum);
    for(i=0;i<choresNum;i++) {
        scanf("%d", &chores[i]);
    }
    sort(chores, choresNum);
    for(i=0;i<choresNum;i++) {
        if(countMins + chores[i] > mins) break;
        countMins += chores[i];
        count++;
    }
    printf("%d", count);
}