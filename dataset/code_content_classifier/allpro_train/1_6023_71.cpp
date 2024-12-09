#include <bits/stdc++.h>
int main() {
  char s[100005];
  int f[7] = {}, min = 100000;
  scanf("%s", s);
  for (int i = 0; s[i]; i++) switch (s[i]) {
      case 'B':
        f[0] += 2;
        break;
      case 'u':
        f[1]++;
        break;
      case 'l':
        f[2] += 2;
        break;
      case 'b':
        f[3] += 2;
        break;
      case 'a':
        f[4]++;
        break;
      case 's':
        f[5] += 2;
        break;
      case 'r':
        f[6] += 2;
    }
  for (int i = 0; i < 7; i++)
    if (f[i] < min) min = f[i];
  printf("%d\n", min / 2);
  return 0;
}
