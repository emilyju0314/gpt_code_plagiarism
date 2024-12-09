#include <bits/stdc++.h>
using namespace std;
char s1[5], s2[5];
int sqr(int n) { return n * n; }
int main() {
  scanf("%s %s", s1, s2);
  int rx = s1[0] - 'a' + 1, ry = s1[1] - '0';
  int kx = s2[0] - 'a' + 1, ky = s2[1] - '0';
  int count = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if ((i == rx || j == ry) || (kx == i && ky == j)) continue;
      if (sqr(i - rx) + sqr(j - ry) != 5 && sqr(i - kx) + sqr(j - ky) != 5)
        count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
