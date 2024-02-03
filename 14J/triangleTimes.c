// 15/15
#include <stdio.h>

typedef enum {
    EQUILATERAL,
    ISOSCELES,
    SCALENE,
    ERROR
} triangle;

triangle triangleType(const int* sides) {
    if(sides[0] + sides[1] + sides[2] != 180) return ERROR;
    if(sides[0] == sides[1] && sides[1] == sides[2]) return EQUILATERAL;
    if(sides[0] == sides[1]
    || sides[1] == sides[2]
    || sides[2] == sides[0]) return ISOSCELES;
    return SCALENE;
}

int main() {
    int sides[3];
    scanf("%d\n%d\n%d", &sides[0], &sides[1], &sides[2]);
    switch(triangleType(sides)) {
        case EQUILATERAL:
            printf("Equilateral");
            break;
        case ISOSCELES:
            printf("Isosceles");
            break;
        case SCALENE:
            printf("Scalene");
            break;
        case ERROR:
            printf("Error");
            break;
    }
}
