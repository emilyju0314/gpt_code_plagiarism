#include <bits/stdc++.h>
using namespace std;
struct T {
  int x, y;
} s[3], t;
int a, v, k;
bool u[1002][1002];
bool cmp(T a, T b) { return a.x < b.x; }
void K(int f) {
  int xx, vv = max(s[0].y, s[2].y), kk = min(s[0].y, s[2].y);
  if (f == 1) {
    printf("%d\n", a);
    for (int i = s[0].x; i <= s[2].x; i++) printf("%d %d\n", i, kk);
    if (kk == s[0].y)
      xx = s[2].x;
    else
      xx = s[0].x;
    for (int i = kk + 1; i <= vv; i++) printf("%d %d\n", xx, i);
  } else if (!f) {
    printf("%d\n", a);
    for (int i = s[0].x; i <= s[2].x; i++) printf("%d %d\n", i, vv);
    if (vv == s[0].y)
      xx = s[2].x;
    else
      xx = s[0].x;
    for (int i = kk; i < vv; i++) printf("%d %d\n", xx, i);
  } else {
    for (int i = s[0].x; i <= s[2].x; i++)
      if (i ^ s[0].x || vv ^ s[0].y) printf("%d %d\n", i, vv);
    if (vv == s[0].y)
      xx = s[2].x;
    else
      xx = s[0].x;
    for (int i = kk; i < vv; i++)
      if (xx ^ s[0].x || i ^ s[0].y) printf("%d %d\n", xx, i);
  }
}
int main() {
  for (int i = 0; i < 3; i++) scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s + 3, cmp), a = s[2].x - s[0].x + abs(s[2].y - s[0].y) + 1;
  v = max(s[0].y, s[2].y), k = min(s[0].y, s[2].y);
  if (s[1].y > v) {
    a += s[1].y - v, K(0);
    for (int i = v + 1; i <= s[1].y; i++) printf("%d %d\n", s[1].x, i);
  } else if (s[1].y < k) {
    a += k - s[1].y, K(1);
    for (int i = s[1].y; i < k; i++) printf("%d %d\n", s[1].x, i);
  } else {
    t = s[2], s[2] = s[1], K(0);
    s[2] = t, s[0] = s[1], K(2);
  }
  return 0;
}
