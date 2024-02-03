#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    int id;
    int idWith;
} person;

typedef struct {
    person people[200];
    int peopleLen;
    int maxId;
} personList;

typedef struct {
    int personOne;
    int personTwo;
} pair;

typedef struct {
    pair pairs[200];
    int pairsLen;
} pairList;

pairList createPairList() {
    pairList ret;
    ret.pairsLen = 0;
    return ret;
}

void appendPairList(pairList* list, int idOne) {
    list->pairs[list->pairsLen++].personOne = idOne;
}

personList createPersonList() {
    personList ret;
    ret.peopleLen = 0;
    ret.maxId = 0;
    return ret;
}

int personId(personList* list, char* name) {
    int i;
    for(i=0;i<list->peopleLen;i++) {
        if(strcmp(list->people[i].name, name) == 0) return list->people[i].id;
    }
    strcpy((char*)&list->people[list->peopleLen++].name, name);
    list->people[list->peopleLen-1].id = list->peopleLen - 1;
    list->people[list->peopleLen-1].idWith = -1;
    return list->peopleLen - 1;
}

void setPartnerId(personList* list, int personId, int partnerId) {
    int i;
    for(i=0;i<list->peopleLen;i++)
        if(list->people[i].id == personId) list->people[i].idWith = partnerId;
}

int partnerId(personList list, int personId) {
    int i;
    for(i=0;i<list.peopleLen;i++) {
        if(list.people[i].id == personId) return list.people[i].idWith;
    }
    return -1;
}

int isValidPairList(pairList pairs, personList people) {
    int i;
    for(i=0;i<people.peopleLen;i++) if(people.people[i].idWith == -1) return 0; // If someone doesn't have a partner
    for(i=0;i<pairs.pairsLen;i++) {
        if(pairs.pairs[i].personOne == pairs.pairs[i].personTwo) return 0;
        if(partnerId(people, pairs.pairs[i].personOne) != pairs.pairs[i].personTwo) return 0;
    }
    return 1;
}

int main() {
    int count, i;
    char name[32];
    personList people = createPersonList();
    pairList pairs = createPairList();
    scanf("%d", &count);
    for(i=0;i<count;i++) {
        scanf("%s", name);
        appendPairList(&pairs, personId(&people, name));
    }
    for(i=0;i<count;i++) {
        scanf("%s", name);
        pairs.pairs[i].personTwo = personId(&people, name);
        setPartnerId(&people, pairs.pairs[i].personTwo, pairs.pairs[i].personOne);
    }
    if(isValidPairList(pairs, people)) printf("good");
    else printf("bad");
}