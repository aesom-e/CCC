// 15/15
#include <stdio.h>

typedef struct {
    char character;
    int num;
} messagePart;

typedef struct {
    messagePart parts[80];
    int len;
} message;

messagePart createMessagePart(int num, char character) {
    messagePart ret;
    ret.num = num;
    ret.character = character;
    return ret;
}

message createMessage() {
    message ret;
    ret.len = 0;
    return ret;
}

void appendMessage(message* in, int num, char character) {
    in->parts[in->len++] = createMessagePart(num, character);
}

void printMessage(message in) {
    int i, j;
    for(i=0;i<in.len;i++) {
        for(j=0;j<in.parts[i].num;j++) {
            printf("%c", in.parts[i].character);
        }
        printf("\n");
    }
}

int main() {
    message mainMessage = createMessage();
    int amount, i, num;
    char character;
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%d %c", &num, &character);
        appendMessage(&mainMessage, num, character);
    }
    printMessage(mainMessage);
}
