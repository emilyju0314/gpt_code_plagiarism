#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const double eps = 1e-10;
mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
template <class T>
inline void upmin(T &x, T y) {
  x = x > y ? y : x;
}
template <class T>
inline void upmax(T &x, T y) {
  x = x < y ? y : x;
}
int n, m;
const int maxn = 410;
struct Two_Sat {
  vector<int> G[maxn];
  int dfn[maxn];
  int low[maxn];
  int scc[maxn];
  int ntime;
  int scc_cnt;
  int sta[maxn];
  int sz;
  bitset<410> ban[maxn];
  vector<int> g[maxn];
  void addedge(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x].push_back(y);
    G[y ^ 1].push_back(x ^ 1);
  }
  void tarjan(int u) {
    dfn[u] = low[u] = ++ntime;
    sta[sz++] = u;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (!scc[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (low[u] == dfn[u]) {
      scc_cnt++;
      g[scc_cnt].clear();
      int tmp;
      do {
        --sz;
        tmp = sta[sz];
        scc[tmp] = scc_cnt;
        g[scc_cnt].emplace_back(tmp);
      } while (tmp != u);
    }
  }
  void init() {
    for (int i = 0; i < 2 * n; i++) G[i].clear();
  }
  bool check() {
    sz = 0;
    memset(scc, 0, sizeof(scc));
    memset(dfn, 0, sizeof(dfn));
    ntime = scc_cnt = 0;
    for (int i = 0; i < 2 * n; ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = 0; i < 2 * n; i += 2) {
      if (scc[i] == scc[i + 1]) return false;
    }
    return true;
  }
  void prepare() {
    for (int i = 1; i <= scc_cnt; i++) ban[i].reset();
    for (int i = 1; i <= scc_cnt; i++) {
      bitset<410> tmp;
      tmp.reset();
      for (auto u : g[i]) tmp[u ^ 1] = 1;
      for (auto u : g[i])
        for (auto v : G[u]) tmp |= ban[v];
      for (auto u : g[i]) ban[u] = tmp;
    }
  }
} sol;
char s[maxn];
int nx[maxn][2];
int x[maxn * maxn], xval[maxn * maxn], y[maxn * maxn], yval[maxn * maxn];
char res[maxn];
char a[maxn][2], b[maxn][2];
int w[maxn];
bitset<410> now[410];
bool dfs(int i, bool f) {
  if (i == n) return 1;
  int c = 0;
  if (!f) {
    int p = w[s[i] - 'a'];
    if (!now[i][i << 1 | p]) {
      now[i + 1] = now[i] | sol.ban[i << 1 | p];
      if (dfs(i + 1, f)) return 1;
    }
    c = s[i] - 'a' + 1;
  }
  int o = nx[c][0] > nx[c][1];
  if (nx[c][o] != -1 && !now[i][i << 1 | o]) {
    now[i + 1] = now[i] | sol.ban[i << 1 | o];
    res[i] = nx[c][o] + 'a';
    if (dfs(i + 1, 1)) return 1;
  }
  o ^= 1;
  if (nx[c][o] != -1 && !now[i][i << 1 | o]) {
    now[i + 1] = now[i] | sol.ban[i << 1 | o];
    res[i] = nx[c][o] + 'a';
    if (dfs(i + 1, 1)) return 1;
  }
  return 0;
}
int main() {
  scanf("%s", s);
  memset(nx, -1, sizeof(nx));
  for (int i = strlen(s) - 1; i >= 0; i--) {
    nx[i][0] = s[i] == 'V' ? i : nx[i + 1][0];
    nx[i][1] = s[i] == 'C' ? i : nx[i + 1][1];
    if (s[i] == 'V')
      w[i] = 0;
    else
      w[i] = 1;
  }
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %s %d %s", &x[i], a[i], &y[i], b[i]);
    x[i]--, y[i]--;
    if (a[i][0] == 'V')
      xval[i] = 0;
    else
      xval[i] = 1;
    if (b[i][0] == 'V')
      yval[i] = 0;
    else
      yval[i] = 1;
    sol.addedge(x[i], xval[i], y[i], yval[i]);
  }
  scanf("%s", s);
  for (int i = 0; i < n; i++) res[i] = s[i];
  res[n] = '\0';
  if (!sol.check()) {
    puts("-1");
    return 0;
  }
  sol.prepare();
  if (!dfs(0, 0))
    puts("-1");
  else
    puts(res);
  return 0;
}
