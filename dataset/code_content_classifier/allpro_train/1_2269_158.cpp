#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int maxn = 1000;
char buffer[maxn], *S, *T;
inline char Get_Char() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, maxn, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f) return -re;
  return re;
}
inline void read(int& x) {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void _write(int x) {
  write(x);
  putchar(' ');
}
inline void print(int x) {
  write(x);
  putchar('\n');
}
const int mxn = 1e6 + 6;
int n, m, root = 0;
pair<int, char> g[mxn][26];
int siz[mxn];
int imp[mxn];
vector<int> qry;
int dp[mxn], par[mxn];
int id[mxn], mn[mxn];
inline bool cmp(pair<int, char> a, pair<int, char> b) {
  return a.second < b.second;
}
int dfn;
void dfs1(int x) {
  dfn += imp[x];
  id[x] = dfn;
  for (register int y = 0; y < siz[x]; ++y) dfs1(g[x][y].first);
}
void dfs2(int x) {
  if (imp[x]) dp[x] = min(dp[x], mn[par[x]] + id[x]);
  dp[x] = min(dp[x], dp[par[x]] + 1);
  mn[x] = min(dp[x] - id[x] + imp[x], mn[par[x]]);
  for (register int i = 0; i < siz[x]; ++i) dfs2(g[x][i].first);
}
inline void solve() {
  read(n);
  for (register int i = 1; i <= n; ++i) {
    int x;
    char c;
    read(x), c = Get_Char();
    g[x][siz[x]++] = {i, c};
    par[i] = x;
  }
  for (register int i = 0; i <= n; ++i) sort(g[i], g[i] + siz[i], cmp);
  read(m);
  for (register int i = 1; i <= m; ++i) {
    int x;
    read(x);
    imp[x] = 1;
    qry.push_back(x);
  }
  memset(dp, 63, sizeof(dp));
  memset(mn, 63, sizeof(mn));
  dp[root] = 0;
  dfs1(root);
  dfs2(root);
  for (register int i = 0; i < qry.size(); ++i) _write(dp[qry[i]]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  for (; T--;) solve();
}
