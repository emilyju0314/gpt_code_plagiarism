#include <bits/stdc++.h>
using namespace std;
struct Thing {
  int p, id;
} a[100001], b[100001];
int an = 0, s1[100001] = {}, bn = 0, s2[100001] = {};
bool cmp(Thing a, Thing b) { return a.p > b.p; }
int n, v, t, p, maxp = 0, ca = 0, cb = 0;
int main() {
  int i;
  scanf("%d%d", &n, &v);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &t, &p);
    if (t == 1) {
      a[++an].p = p;
      a[an].id = i;
    } else {
      b[++bn].p = p;
      b[bn].id = i;
    }
  }
  sort(a + 1, a + an + 1, cmp);
  sort(b + 1, b + bn + 1, cmp);
  if (!an) {
    for (i = 1; i <= n && 2 * i <= v; i++) maxp += b[i].p;
    printf("%d\n", maxp);
    for (i = 1; i <= n && 2 * i <= v; i++) printf("%d ", b[i].id);
    return 0;
  }
  if (!bn) {
    for (i = 1; i <= n && i <= v; i++) maxp += a[i].p;
    printf("%d\n", maxp);
    for (i = 1; i <= n && i <= v; i++) printf("%d ", a[i].id);
    return 0;
  }
  for (i = 1; i <= an; i++) s1[i] = s1[i - 1] + a[i].p;
  for (i = 1; i <= bn; i++) s2[i] = s2[i - 1] + b[i].p;
  for (i = 0; i <= an && i <= v; i++) {
    if (s1[i] + s2[min((v - i) / 2, bn)] > maxp) {
      maxp = s1[i] + s2[min((v - i) / 2, bn)];
      ca = i, cb = min((v - i) / 2, bn);
    }
  }
  printf("%d\n", maxp);
  for (i = 1; i <= ca; i++) printf("%d ", a[i].id);
  for (i = 1; i <= cb; i++) printf("%d ", b[i].id);
  return 0;
}
