#include <bits/stdc++.h>
int sign(char ch) {
  switch (ch) {
    case 'v':
      return 0;
    case '<':
      return 1;
    case '^':
      return 2;
    case '>':
      return 3;
  }
}
int main(void) {
  int s, g, n;
  char ch = getchar();
  s = sign(ch);
  getchar();
  ch = getchar();
  g = sign(ch);
  int step = (g - s + 4) % 4;
  scanf("%d", &n);
  n %= 4;
  bool cw = step == n;
  bool ccw = (step + n) % 4 == 0;
  if (cw && !ccw)
    printf("cw\n");
  else if (!cw && ccw)
    printf("ccw\n");
  else
    printf("undefined\n");
  return 0;
}
