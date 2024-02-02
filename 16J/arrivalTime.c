// 15/15
#include <stdio.h>

int floor(float in) {
    int i;
    for(i=0;i>-1&&i<=in;i++);
    return i-1;
}

int isRushHour(int minutes) {
    if(minutes >= 420 && minutes <= 600) return 1;
    if(minutes >= 900 && minutes <= 1140) return 1;
    return 0;
}

int calculateTime(int startTime) {
    int time = startTime, i;
    for(i=0;i<120;i++) {
        if(isRushHour(time) && isRushHour(time+1)) time += 2;
        else time++;
    }
    return (time % 1440);
}

void printTime(int time) {
    float hoursRaw = time;
    // Because of float weirdness I can't do this inline
    hoursRaw /= 60;
    int hours = floor(hoursRaw);
    int minutes = time % 60;
    if(hours<10) printf("0");
    printf("%d:", hours);
    if(minutes<10) printf("0");
    printf("%d", minutes);
}

int main() {
    int hours, minutes;
    scanf("%d:%d", &hours, &minutes);
    minutes += (hours * 60);
    printTime(calculateTime(minutes));
}
