#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getchar();
}
int n, m, a[1000005], b[1000005], c[1000005 << 1], tot, t[1000005 << 1],
    s[1000005 << 2], la[1000005 << 2];
vector<int> k[1000005 << 1];
long long ans;
inline void add(int x, int y) {
  for (int i = x; i <= tot; i += i & -i) t[i] += y;
}
inline int ask(int x) {
  int s = 0;
  for (int i = x; i; i -= i & -i) s += t[i];
  return s;
}
inline void build(int p, int l, int r) {
  s[p] = la[p] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}
inline void add(int p, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return s[p] += z, la[p] += z, void();
  int mid = (l + r) >> 1;
  if (la[p])
    s[p << 1] += la[p], s[p << 1 | 1] += la[p], la[p << 1] += la[p],
        la[p << 1 | 1] += la[p], la[p] = 0;
  if (mid >= x) add(p << 1, l, mid, x, y, z);
  if (mid < y) add(p << 1 | 1, mid + 1, r, x, y, z);
  s[p] = min(s[p << 1], s[p << 1 | 1]);
}
int main() {
  int T;
  read(T);
  while (T--) {
    read(n), read(m), ans = tot = 0;
    for (int i = 1; i <= n; i++) read(a[i]), c[++tot] = a[i];
    for (int i = 1; i <= m; i++) read(b[i]), c[++tot] = b[i];
    sort(c + 1, c + tot + 1), tot = unique(c + 1, c + tot + 1) - c - 1;
    for (int i = 1; i <= n; i++)
      a[i] = lower_bound(c + 1, c + tot + 1, a[i]) - c;
    for (int i = 1; i <= m; i++)
      b[i] = lower_bound(c + 1, c + tot + 1, b[i]) - c;
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= tot; i++) t[i] = 0, k[i].clear();
    for (int i = 1; i <= n; i++) k[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) ans += ask(tot) - ask(a[i]), add(a[i], 1);
    build(1, 0, n);
    for (int i = 1; i <= n; i++) add(1, 0, n, i, n, 1);
    for (int i = 1, las1 = 0, las2 = 0; i <= m; i++) {
      while (las1 < b[i]) {
        ++las1;
        for (auto &j : k[las1]) add(1, 0, n, j, n, -1);
      }
      while (las2 < b[i] - 1) {
        ++las2;
        for (auto &j : k[las2]) add(1, 0, n, 0, j - 1, 1);
      }
      ans += s[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
