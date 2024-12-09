#include <stdio.h>

int main(void) {
  int t;
  scanf("%d", &t);
  while(t--) {
    int s;
    scanf("%d", &s);
    for (int i = 0; i < 100; i++) {
      if (i * i >= s) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
