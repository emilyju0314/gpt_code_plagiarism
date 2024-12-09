#include <bits/stdc++.h>
using namespace std;
const int lim = 10;
char ch[11];
int i, j, k, n, m, a[21], t;
int main() {
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%s%d", ch, &k);
    if (ch[0] == '&') {
      for (j = 0; j < lim; j++) {
        t = ((k >> j) & 1);
        if (!t) a[j] = 2;
      }
    }
    if (ch[0] == '|') {
      for (j = 0; j < lim; j++) {
        t = ((k >> j) & 1);
        if (t) a[j] = 3;
      }
    }
    if (ch[0] == '^') {
      for (j = 0; j < lim; j++) {
        t = ((k >> j) & 1);
        if (t) a[j] ^= 1;
      }
    }
  }
  puts("3");
  for (k = i = 0; i < lim; i++) k += ((a[i] & 1) << i);
  printf("^ %d\n", k);
  for (k = i = 0; i < lim; i++)
    if (a[i] != 2) k += (1 << i);
  printf("& %d\n", k);
  for (k = i = 0; i < lim; i++)
    if (a[i] == 3) k += (1 << i);
  printf("| %d\n", k);
  return 0;
}
