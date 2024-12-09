#include <bits/stdc++.h>
int n, m, b, a, d, c[505][505];
int main() {
  scanf("%d %d %d %d", &n, &m, &b, &d);
  for (int i = (0); i < (505); i++) c[0][i] = 1;
  for (int i = (0); i < (n); i++) {
    scanf("%d", &a);
    for (int l = (1); l < (505); l++)
      for (int g = (a); g < (505); g++)
        c[l][g] = (c[l][g] + c[l - 1][g - a]) % d;
  }
  printf("%d\n", c[m][b]);
}
