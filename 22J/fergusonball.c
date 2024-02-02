// 15/15
#include <stdio.h>

int main() {
    int players = 0, points = 0, fouls = 0, golds = 0, i;
    scanf("%d", &players);
    for(i=0;i<players;i++) {
        scanf("%d\n%d", &points, &fouls);
        if((points * 5) - (fouls * 3) > 40) golds++;
    }
    printf("%d", golds);
    if(golds == players) printf("+");
}
