// 15/15
#include <stdio.h>
#include <string.h>

typedef struct {
    char letters[21];
    char lettersLen;
    char tighten;
    int turns;
} instruction;

typedef enum {
    LETTER,
    TURNS
} stage;

void printInstruction(instruction in) {
    printf("%s ", in.letters);
    if(in.tighten) printf("tighten ");
    else printf("loosen ");
    printf("%d\n", in.turns);
}

instruction createBlankInstruction() {
    instruction ret;
    ret.turns = 0;
    ret.tighten = 0;
    int i;
    for(i=0;i<21;i++) ret.letters[i] = 0;
    ret.lettersLen = 0;
    return ret;
}

void appendLetter(instruction* in, char letter) {
    in->letters[in->lettersLen++] = letter;
}

void appendNumber(instruction* in, int number) {
    in->turns *= 10;
    in->turns += number;
}

int getInt(char in) {
    int temp = in - '0';
    if(temp < 10 && temp > -1) return temp;
    return -1;
}

int main() {
    char input[401];
    fgets(input, 400, stdin);
    instruction curInstruction = createBlankInstruction();
    int len = strlen(input), i;
    stage curStage = LETTER;
    for(i=0;i<len;i++) {
        if(input[i] == '+') { curInstruction.tighten = 1; curStage = TURNS; continue;}
        if(input[i] == '-') { curInstruction.tighten = 0; curStage = TURNS; continue;}
        if(curStage == LETTER) { appendLetter(&curInstruction, input[i]); continue; }
        // curStage == TURNS
        if(getInt(input[i]) == -1) {
            printInstruction(curInstruction);
            curStage = LETTER;
            curInstruction = createBlankInstruction();
            appendLetter(&curInstruction, input[i]);
            continue;
        }
        appendNumber(&curInstruction, getInt(input[i]));
    }
}
