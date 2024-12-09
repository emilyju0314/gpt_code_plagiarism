#include <bits/stdc++.h>
template <typename Y>
inline bool updmin(Y &a, Y b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline bool updmax(Y &a, Y b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline Y abs(Y a) {
  if (a < 0) a = -a;
  return a;
}
template <typename Y>
inline Y sqr(Y a) {
  return a * a;
}
int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}
inline void FileIO() {
  freopen(
      ""
      ".in",
      "r", stdin);
  freopen(
      ""
      ".out",
      "w", stdout);
}
int n, m, h;
const int N = 100020;
std::vector<int> G[N], s;
int tim = 0, cnt = 0;
int low[N], dfn[N], vis[N], bel[N];
void tarjan(int p) {
  vis[p] = 1;
  s.push_back(p);
  low[p] = dfn[p] = ++tim;
  for (int t : G[p]) {
    if (!dfn[t]) {
      tarjan(t);
      updmin(low[p], low[t]);
    } else if (vis[t]) {
      updmin(low[p], dfn[t]);
    }
  }
  if (low[p] == dfn[p]) {
    ++cnt;
    while (s.back() != p) {
      int cur = s.back();
      s.pop_back();
      vis[cur] = 0;
      bel[cur] = cnt;
    }
    bel[p] = cnt;
    vis[p] = 0;
    s.pop_back();
  }
}
int u[N], size[N], out[N];
int main() {
  n = read();
  m = read();
  h = read();
  for (int i = 1; i <= n; i++) {
    u[i] = read();
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    if ((u[x] + 1) % h == u[y]) {
      G[x].push_back(y);
    }
    if ((u[y] + 1) % h == u[x]) {
      G[y].push_back(x);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    size[bel[i]]++;
    for (int j : G[i]) {
      if (bel[i] != bel[j]) {
        out[bel[i]]++;
      }
    }
  }
  int ans = n + 1, pos = 0;
  for (int i = 1; i <= cnt; i++) {
    if (!out[i] && updmin(ans, size[i])) {
      pos = i;
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    if (bel[i] == pos) {
      printf("%d ", i);
    }
  }
  return 0;
}
