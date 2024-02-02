// 15/15
#include <stdio.h>

int main() {
   int apple, banana, a, b, c;
   scanf("%d\n%d\n%d", &a, &b, &c);
   apple = (a*3) + (b*2) + c;
   scanf("%d\n%d\n%d", &a, &b, &c);
   banana = (a*3) + (b*2) + c;
   if(apple == banana) { printf("T"); return 0; }
   if(apple > banana) { printf("A"); return 0; }
   printf("B");
}
