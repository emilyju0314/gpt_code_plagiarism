#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int x = 0, f = 1, c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 200005;
int n, m, k, ql, qr, q[MAXN], d[MAXN], l[MAXN], r[MAXN], ans[MAXN];
vector<int> adj[MAXN], add[MAXN];
set<pair<int, int> > cur;
int main() {
  n = Read(), m = Read(), k = Read();
  for (int i = 1; i <= n; i++) {
    int x = Read();
    if (!x)
      l[i] = 1, r[i] = k;
    else
      l[i] = r[i] = x;
  }
  for (int i = 1, x, y; i <= m; i++)
    x = Read(), y = Read(), adj[x].push_back(y), d[y]++;
  for (int i = 1; i <= n; i++)
    if (!d[i]) q[++qr] = i;
  while (ql ^ qr) {
    int x = q[++ql];
    for (auto y : adj[x])
      if (!--d[y]) q[++qr] = y;
  }
  if (qr ^ n) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) {
    int x = q[i];
    for (auto y : adj[x]) r[y] = min(r[y], r[x] - 1);
  }
  for (int i = n; i; i--) {
    int x = q[i];
    for (auto y : adj[x]) l[x] = max(l[x], l[y] + 1);
  }
  for (int i = 1; i <= n; i++)
    if (l[i] > r[i]) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) add[l[i]].push_back(i);
  for (int i = 1; i <= k; i++) {
    for (auto x : add[i]) cur.insert(make_pair(r[x], x));
    if (cur.empty()) return puts("-1"), 0;
    pair<int, int> v = *cur.begin();
    ans[v.second] = i;
    cur.erase(cur.begin());
    while (!cur.empty() && (v = *cur.begin()).first == i)
      ans[v.second] = i, cur.erase(cur.begin());
  }
  for (int x = 1; x <= n; x++)
    for (auto y : adj[x])
      if (ans[x] <= ans[y]) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
