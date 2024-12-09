#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int a[maxn], n;
int mp[maxn], p[maxn];
bool cal(int x, int y, int p1, int p2) {
  for (int i = 0; i <= n; i++) p[i] = 0;
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      p[abs(i - p1) + abs(j - p2)]++;
    }
  }
  for (int i = 0; i <= n; i++)
    if (p[i] != mp[i]) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ++mp[a[i]];
    mx = max(mx, a[i]);
  }
  int t = 1;
  while (mp[t] == 4 * t) ++t;
  for (int x = 1; x * x <= n; x++) {
    int y = n / x;
    int r = y - (mx - (x - t));
    if (r < 0 || r > y) continue;
    if (cal(x, y, t, r)) {
      printf("%d %d\n%d %d\n", x, y, t, r);
      return 0;
    }
    r = x - (mx - (y - t));
    if (r < 0 || r > x) continue;
    if (cal(x, y, r, t)) {
      printf("%d %d\n%d %d\n", x, y, r, t);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
