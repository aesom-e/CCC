#include <stdio.h>

typedef struct {
    int data[100];
} row;

typedef struct {
    row rows[100];
    char rowsLen;
} table;

table createTable() {
    table ret;
    ret.rowsLen = 0;
    return ret;
}

void printTable(table in) {
    int i, j;
    for(i=0;i<in.rowsLen;i++) {
        for(j=0;j<in.rowsLen;j++) {
            printf("%d ", in.rows[i].data[j]);
        }
        printf("\n");
    }
}

row populateRow(const int* data, char dataLen) {
    char i;
    row ret;
    for(i=0;i<dataLen;i++) {
        ret.data[i] = data[i];
    }
    return ret;
}

void appendTable(table* tableIn, const int* data, char dataLen) {
    tableIn->rows[tableIn->rowsLen++] = populateRow(data, dataLen);
}

table rotateTable(table tableIn) {
    table ret;
    ret.rowsLen = tableIn.rowsLen;
    char x, y;
    for(y=0;y<tableIn.rowsLen;y++) {
        for(x=0;x<tableIn.rowsLen;x++) {
            ret.rows[y].data[x] = tableIn.rows[x].data[tableIn.rowsLen-1-y];
        }
    }
    return ret;
}

int validTable(table tableIn) {
    int maxHeight = 0, i, j;
    for(i=0;i<tableIn.rowsLen;i++) {
        if(maxHeight>tableIn.rows[i].data[0]) return 0;
        maxHeight = tableIn.rows[i].data[0];
    }
    for(i=0;i<tableIn.rowsLen;i++) {
        maxHeight = 0;
        for(j=0;j<tableIn.rowsLen;j++) {
            if(maxHeight>tableIn.rows[i].data[j]) return 0;
            maxHeight = tableIn.rows[i].data[j];
        }
    }
    return 1;
}

int main() {
    int amount, i, j, data[100];
    table dataTable = createTable();
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        for(j=0;j<amount;j++) {
            scanf("%d", &data[j]);
        }
        appendTable(&dataTable, data, (char)amount);
    }
    while(!validTable(dataTable)) dataTable = rotateTable(dataTable);
    printTable(dataTable);
}