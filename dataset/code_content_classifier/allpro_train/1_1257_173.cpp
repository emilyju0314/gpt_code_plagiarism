#include <bits/stdc++.h>
using namespace std;
int T, a, b, x, tmp;
char s[10], t[10];
int main() {
  a = -2000000000;
  b = 2000000000;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%d%s", &s, &x, &t);
    if (!strcmp(s, ">="))
      tmp = 1;
    else if (!strcmp(s, ">"))
      tmp = 2;
    else if (!strcmp(s, "<="))
      tmp = 3;
    else if (!strcmp(s, "<"))
      tmp = 4;
    if (t[0] == 'N') tmp = 5 - tmp;
    if (tmp == 1)
      a = max(x, a);
    else if (tmp == 2)
      a = max(x + 1, a);
    else if (tmp == 3)
      b = min(x, b);
    else if (tmp == 4)
      b = min(x - 1, b);
    if (a > b) return puts("Impossible"), 0;
  }
  printf("%d\n", a);
  return 0;
}
