// 15/15
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int topLeft;
    int topRight;
    int bottomLeft;
    int bottomRight;
} board;

board createBoard() {
    board ret;
    ret.topLeft = 1;
    ret.topRight = 2;
    ret.bottomLeft = 3;
    ret.bottomRight = 4;
    return ret;
}

void flipVertical(board* in) {
    int temp = in->topRight;
    in->topRight = in->topLeft;
    in->topLeft = temp;
    temp = in->bottomRight;
    in->bottomRight = in->bottomLeft;
    in->bottomLeft = temp;
}

void flipHorizontal(board* in) {
    int temp = in->topLeft;
    in->topLeft = in->bottomLeft;
    in->bottomLeft = temp;
    temp = in->topRight;
    in->topRight = in->bottomRight;
    in->bottomRight = temp;
}

int main() {
    board gameBoard = createBoard();
    char* line = (char*)malloc(sizeof(char)*1000001);
    scanf("%s", line);
    int len = strlen(line), i, horizontal = 0, vertical = 0;
    for(i=0;i<len;i++) {
        if(line[i] == 'H') horizontal++;
        if(line[i] == 'V') vertical++;
    }
    if(horizontal % 2 == 1) flipHorizontal(&gameBoard);
    if(vertical % 2 == 1) flipVertical(&gameBoard);
    printf("%d %d\n%d %d", gameBoard.topLeft, gameBoard.topRight,
           gameBoard.bottomLeft, gameBoard.bottomRight);
}
