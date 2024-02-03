#include <stdio.h>

typedef struct {
    char people[100];
    int peopleLen;
} list;

list createList(int len) {
    list ret;
    ret.peopleLen = len;
    int i;
    for(i=0;i<len;i++) ret.people[i] = 1;
    return ret;
}

void removePeople(list* listIn, int multiple) {
    int i, count = 0;
    for(i=0;i<listIn->peopleLen;i++) {
        if(listIn->people[i]) count++;
        if(count == multiple) { count = 0; listIn->people[i] = 0; }
    }
}

void printList(list in) {
    int i;
    for(i=0;i<in.peopleLen;i++) {
        if(in.people[i]) printf("%d\n", i+1);
    }
}

int main() {
    int listLen, count, i, multiple;
    scanf("%d\n%d", &listLen, &count);
    list mainList = createList(listLen);
    for(i=0;i<count;i++) {
        scanf("%d", &multiple);
        removePeople(&mainList, multiple);
    }
    printList(mainList);
}