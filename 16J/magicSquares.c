// 15/15
#include <stdio.h>

typedef struct {
    int data[4];
} row;

typedef struct {
    row rows[4];
} square;

int rowSum(square in, int rowNum) {
    int count = 0, i;
    for(i=0;i<4;i++) count += in.rows[rowNum].data[i];
    return count;
}

int columnSum(square in, int columnNum) {
    int count = 0, i;
    for(i=0;i<4;i++) count += in.rows[i].data[columnNum];
    return count;
}

int isMagic(square in) {
    int i, sum = rowSum(in, 0);
    for(i=1;i<4;i++) if(rowSum(in, i) != sum) return 0;
    for(i=0;i<4;i++) if(columnSum(in, i) != sum) return 0;
    return 1;
}

int main() {
    int i, j, input[5]; // 5 because of a stack smashing error if 4
    square mainSquare;
    for(i=0;i<4;i++) {
        scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
        for(j=0;j<4;j++) mainSquare.rows[i].data[j] = input[j];
    }
    if(isMagic(mainSquare)) printf("magic");
    else printf("not magic");
}
