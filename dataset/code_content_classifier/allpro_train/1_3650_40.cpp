#include <bits/stdc++.h>
using namespace std;
int n, p, k;
char a[100005];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", a + 1);
  p = 1;
  while (k > 0) {
    while (p < n && (a[p] != '4' || a[p + 1] != '7')) p++;
    if (p >= n) break;
    if (p & 1 ^ 1) {
      a[p] = '7', p--;
      k--;
      continue;
    }
    if (a[p + 2] != '7') {
      k--, a[++p] = '4', p++;
      continue;
    }
    if (k & 1)
      a[p + 1] = '4';
    else
      a[p + 1] = '7';
    break;
  }
  printf("%s", a + 1);
}