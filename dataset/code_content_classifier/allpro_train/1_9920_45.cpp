#include <bits/stdc++.h>
template <typename T>
bool Chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool Chkmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
const int MAXL = 1e7 + 1e3, MAXN = 750 + 100;
int n;
char s[MAXL];
int pos[MAXN];
int g[MAXN][MAXN];
namespace Trie {
const int MAXSIZE = 1e5 + 1e4, MAXCH = 2;
int size;
int val[MAXL];
int f[MAXL];
int ch[MAXL][2];
int last[MAXL];
inline int Idx(char x) { return x - 'a'; }
void Insert(char *s, int w) {
  int u = 0, len = strlen(s);
  for (int i = 0, _ = len - 1; i <= _; ++i) {
    int &v = ch[u][Idx(s[i])];
    if (!v) v = ++size;
    u = v;
    if (i == len - 1) val[u] = w;
  }
}
void GetFail() {
  std::queue<int> q;
  for (int i = 0, _ = MAXCH - 1; i <= _; ++i)
    if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c = 0, _ = MAXCH - 1; c <= _; ++c) {
      int &v = ch[u][c];
      if (!v)
        v = ch[f[u]][c];
      else {
        q.push(v);
        int j = f[u];
        while (j && !ch[j][c]) j = f[j];
        f[v] = ch[j][c];
        last[v] = val[f[v]] ? f[v] : last[f[v]];
      }
    }
  }
}
}  // namespace Trie
namespace Hungary {
int cur;
int G[MAXN * 2][MAXN * 2];
int flag[MAXN * 2];
int match[MAXN * 2];
bool Dfs(int u) {
  static int vis[MAXN * 2];
  for (int i = n + 1, _ = n * 2; i <= _; ++i) {
    if (!G[u][i] || vis[i] == cur) continue;
    vis[i] = cur;
    if (!match[i] || Dfs(match[i])) {
      match[i] = u;
      return true;
    }
  }
  return false;
}
void Dfs0(int u) {
  if (flag[u]) return;
  flag[u] = true;
  for (int i = n + 1, _ = n * 2; i <= _; ++i)
    if (G[u][i]) {
      flag[i] = true;
      Dfs0(match[i]);
    }
}
int Exec() {
  static int no[MAXN];
  int tot = 0;
  for (int i = 1, _ = n; i <= _; ++i)
    for (int j = 1, _ = n; j <= _; ++j)
      if (i != j && g[i][j]) G[i][j + n] = true;
  for (int i = 1, _ = n; i <= _; ++i) {
    ++cur;
    if (Dfs(i))
      ++tot;
    else
      no[i] = true;
  }
  for (int i = 1, _ = n; i <= _; ++i)
    if (no[i]) Dfs0(i);
  return tot;
}
}  // namespace Hungary
void Solve() {
  {
    using namespace Trie;
    GetFail();
    for (int i = 1, _ = n; i <= _; ++i) {
      int u = 0;
      for (int j = pos[i], _ = pos[i + 1] - 1; j <= _; ++j) {
        u = ch[u][Idx(s[j])];
        int k = val[u] && val[u] != i ? u : last[u];
        if (val[k]) g[i][val[k]] = true;
      }
    }
  }
  for (int k = 1, _ = n; k <= _; ++k)
    for (int i = 1, _ = n; i <= _; ++i)
      for (int j = 1, _ = n; j <= _; ++j) g[i][j] |= g[i][k] & g[k][j];
  printf("%d\n", n - Hungary::Exec());
  for (int i = 1, _ = n; i <= _; ++i)
    if (Hungary::flag[i] && !Hungary::flag[i + n]) printf("%d ", i);
  puts("");
}
void Input() {
  scanf("%d", &n);
  for (int i = 1, _ = n; i <= _; ++i) {
    scanf("%s", s + pos[i]);
    Trie::Insert(s + pos[i], i);
    pos[i + 1] = pos[i] + strlen(s + pos[i]);
  }
}
int main() {
  if (fopen("E.in", "r") != NULL) {
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
  }
  Input();
  Solve();
  return 0;
}
