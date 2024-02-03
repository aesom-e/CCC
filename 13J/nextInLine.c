#include <stdio.h>

int main() {
    int young, middle;
    scanf("%d\n%d", &young, &middle);
    printf("%d", middle + (middle - young));
}