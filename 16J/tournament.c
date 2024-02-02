#include <stdio.h>

int getGroup(int wins) {
    if(wins>=5) return 1;
    if(wins>=3) return 2;
    if(wins>=1) return 3;
    return -1;
}

int main() {
    int i, wins = 0;
    char input[3]; // Contains the letter, \n, and \0
    for(i=0;i<6;i++) {
        scanf("%s", input);
        if(input[0] == 'W') wins++;
    }
    printf("%d", getGroup(wins));
}