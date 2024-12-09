#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    char a[101], b[101], c[101];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    int s = strlen(a);
    int i = 0;
    for (i = 0; i < s; i++) {
      if (a[i] == c[i]) {
        continue;
      } else if (b[i] == c[i]) {
        continue;
      } else {
        printf("NO\n", i);
        break;
      }
    }
    if (i > s - 1) {
      printf("YES\n");
    }
  }
}
