#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
int q, n, len, ans;
int a[300010], l[300010], r[300010], c[300010], f[300010], g[300010];
vector<int> v;
vector<int> e[300010];
int lowbit(int x) { return x & -x; }
void add(int x, int val) {
  for (int i = x; i <= len; i += lowbit(i)) c[i] = max(c[i], val);
}
int query(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) res = max(res, c[i]);
  return res;
}
int main() {
  q = read();
  while (q--) {
    n = read(), v.clear();
    for (int i = 1; i <= n; i++)
      l[i] = 0x3f3f3f3f, r[i] = -0x3f3f3f3f, e[i].clear();
    for (int i = 1; i <= n; i++) a[i] = read(), v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    len = v.size();
    for (int i = 0; i <= len; i++) c[i] = 0, f[i] = g[i] = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
      l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    }
    for (int i = 1; i <= len; i++) e[l[i]].push_back(i), e[r[i]].push_back(-i);
    for (int i = 1; i <= n; i++) {
      for (auto u : e[i])
        if (u > 0) f[u] = g[u - 1] + 1;
      for (auto u : e[i])
        if (u < 0) g[-u] = f[-u];
    }
    ans = 0;
    for (int i = 1; i <= len; i++) ans = max(ans, g[i]);
    printf("%d\n", len - ans);
  }
  return 0;
}
