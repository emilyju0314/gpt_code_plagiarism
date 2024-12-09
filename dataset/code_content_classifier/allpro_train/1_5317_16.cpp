#include <bits/stdc++.h>
int a, b, w, x, c;
int v1[(1024)];
int v2[(1024)];
int main() {
  scanf("%d %d %d %d %d", &a, &b, &w, &x, &c);
  c -= a;
  if (c <= 0) {
    printf("0\n");
    return 0;
  }
  memset(v1, -1, sizeof(v1));
  memset(v2, -1, sizeof(v2));
  int i, j;
  long long sol = 0;
  i = b;
  j = 0;
  while (v1[i] == -1) {
    v1[i] = sol;
    v2[i] = j;
    if (i >= x) {
      i -= x;
      ++j;
      --c;
    } else
      i += w - x;
    ++sol;
    if (c == 0) {
      printf("%I64d\n", sol);
      return 0;
    }
  }
  int t = sol - v1[i];
  int d = j - v2[i];
  long long q = (c - 1) / d;
  sol += q * t;
  c -= q * d;
  while (c > 0) {
    if (i >= x) {
      i -= x;
      --c;
    } else
      i += w - x;
    ++sol;
  }
  printf("%I64d\n", sol);
  return 0;
}
