#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, k, l, r, mi, p1, p2, cont;
int v[N], a[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  p1 = p2 = 0;
  cont = 1;
  a[v[0]]++;
  while (cont < k && p2 < n) {
    p2++;
    if (a[v[p2]]++ == 0) cont++;
  }
  if (p2 >= n) {
    printf("-1 -1\n");
    return 0;
  }
  l = p1;
  r = p2;
  mi = r - l + 1;
  while (p2 < n) {
    while (p2 < n && cont < k) {
      p2++;
      if (a[v[p2]]++ == 0) cont++;
    }
    while (p2 < n && cont >= k) {
      if (p2 - p1 + 1 < mi) {
        l = p1;
        r = p2;
        mi = r - l + 1;
      }
      if (--(a[v[p1]]) == 0) cont--;
      p1++;
    }
  }
  printf("%d %d\n", l + 1, r + 1);
  return 0;
}
