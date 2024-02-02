#include <stdio.h>
#include <string.h>

typedef struct {
    char name[11];
    int id;
} person;

typedef struct {
    person people[200];
    int peopleLen;
    int maxId;
} personList;

typedef struct {
    int idOne;
    int idTwo;
    char together; // 1 if they must be together, 0 if they must be apart
    char broken;
} constraint;

typedef struct {
    constraint constraints[100];
    int constraintsLen;
} constraintList;

typedef struct {
    int idOne;
    int idTwo;
    int idThree;
} group;

typedef struct {
    group groups[50];
    int groupsLen;
} groupList;

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
    return list->peopleLen - 1;
}

constraintList createConstraintList() {
    constraintList ret;
    ret.constraintsLen = 0;
    return ret;
}

void addConstraint(constraintList* list, int idOne, int idTwo, char together) {
    list->constraints[list->constraintsLen].broken = 0;
    list->constraints[list->constraintsLen].idOne = idOne;
    list->constraints[list->constraintsLen].idTwo = idTwo;
    list->constraints[list->constraintsLen++].together = together;
}

groupList createGroupList() {
    groupList ret;
    ret.groupsLen = 0;
    return ret;
}

void addGroup(groupList* list, int idOne, int idTwo, int idThree) {
    list->groups[list->groupsLen].idOne = idOne;
    list->groups[list->groupsLen].idTwo = idTwo;
    list->groups[list->groupsLen++].idThree = idThree;
}

int xor(int conditionOne, int conditionTwo) {
    if(conditionOne && conditionTwo) return 0;
    if(conditionOne || conditionTwo) return 1;
    return 0;
}

int inGroup(group groupIn, int id) {
    if(id == groupIn.idOne
    || id == groupIn.idTwo
    || id == groupIn.idThree) return 1;
    return 0;
}

void singleViolates(group groupIn, constraint* constraintIn) {
    if(constraintIn->together) {
        if(xor(inGroup(groupIn, constraintIn->idOne), inGroup(groupIn, constraintIn->idTwo)) && !constraintIn->broken) {
            constraintIn->broken = 1;
            return;
        }
    } else {
        if(inGroup(groupIn, constraintIn->idOne) && inGroup(groupIn, constraintIn->idTwo) && !constraintIn->broken) {
            constraintIn->broken = 1;
            return;
        }
    }
}

void computeViolations(group groupIn, constraintList* constraints) {
    int i;
    for(i=0;i<constraints->constraintsLen;i++) {
        singleViolates(groupIn, &constraints->constraints[i]);
    }
}

int main() {
    int amount, i, violations = 0;
    char nameOne[11], nameTwo[11], nameThree[11];
    personList list = createPersonList();
    constraintList constraints = createConstraintList();
    groupList groups = createGroupList();
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%s %s", nameOne, nameTwo);
        addConstraint(&constraints, personId(&list, nameOne), personId(&list, nameTwo), 1);
    }
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%s %s", nameOne, nameTwo);
        addConstraint(&constraints, personId(&list, nameOne), personId(&list, nameTwo), 0);
    }
    scanf("%d", &amount);
    for(i=0;i<amount;i++) {
        scanf("%s %s %s", nameOne, nameTwo, nameThree);
        addGroup(&groups, personId(&list, nameOne), personId(&list, nameTwo), personId(&list, nameThree));
    }
    for(i=0;i<groups.groupsLen;i++) {
        computeViolations(groups.groups[i], &constraints);
    }
    for(i=0;i<constraints.constraintsLen;i++) {
        if(constraints.constraints[i].broken) violations++;
    }
    printf("%d", violations);
}