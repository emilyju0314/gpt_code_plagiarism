#include <bits/stdc++.h>
inline int in() {
  int k = 0;
  char ch = getchar();
  while (ch < '-') ch = getchar();
  while (ch > '-') k = k * 10 + ch - '0', ch = getchar();
  return k;
}
int m, n, tmp[40], lim, *a = tmp, ans;
std::set<int> cx;
std::set<int>::iterator it;
using std::max;
void dfs(int d, int now) {
  if (now >= m) now -= m;
  if (d == lim + 1) {
    ans = max(ans, now);
    cx.insert(now);
    return;
  }
  dfs(d + 1, now);
  dfs(d + 1, now + a[d]);
}
void Dfs(int d, int now) {
  if (now >= m) now -= m;
  if (d == n + 1) {
    it = cx.lower_bound(m - now);
    if (it == cx.begin()) return;
    --it;
    ans = max(ans, (*it) + now);
    return;
  }
  Dfs(d + 1, now);
  Dfs(d + 1, now + a[d]);
}
int main() {
  n = in(), m = in();
  lim = n + 1 >> 1;
  cx.insert(0);
  for (int i = 1; i <= n; ++i) a[i] = in() % m;
  dfs(1, 0), Dfs(lim + 1, 0);
  printf("%d\n", ans);
  return 0;
}
