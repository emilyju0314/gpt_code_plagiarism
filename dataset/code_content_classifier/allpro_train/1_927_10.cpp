#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mo = 998244353;
const int inv2 = 499122177;
const int jzm = 2333;
const int orG = 3, invG = 332748118;
const int lim = 300000;
const double Pi = acos(-1.0);
const double PI = acos(-1.0);
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
template <typename _T>
void print(_T x) {
  if (x < 0) {
    x = (~x) + 1;
    putchar('-');
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int add(int x, int y) { return x + y < mo ? x + y : x + y - mo; }
int qkpow(int a, int s) {
  int t = 1;
  while (s) {
    if (s & 1) t = 1ll * a * t % mo;
    a = 1ll * a * a % mo;
    s >>= 1;
  }
  return t;
}
int n, m, head[500005], tot, dp[500005], g[500005], dfn[500005], low[500005],
    belong[500005];
int sta[500005], stak, idx, cnt, q[2][500005 << 1], Head[2], Tail[2],
    ans[500005];
int dis[500005], ord[500005], tid, mxd[500005];
bool vis[500005];
vector<int> cir[500005];
queue<int> Q;
struct edge {
  int to, nxt;
} e[500005 << 3];
void addEdge(int u, int v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
void bfs(int s) {
  while (!Q.empty()) Q.pop();
  Q.push(s);
  dis[s] = 1;
  vis[s] = 1;
  while (!Q.empty()) {
    int t = Q.front();
    Q.pop();
    ord[++tid] = t;
    for (int i = head[t]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (vis[v]) continue;
      Q.push(v);
      vis[v] = 1;
      dis[v] = dis[t] + 1;
    }
  }
  for (int i = tid; i > 0; i--) {
    int u = ord[i];
    mxd[u] = dis[u];
    for (int j = head[u]; j; j = e[j].nxt) mxd[u] = max(mxd[e[j].to], mxd[u]);
    dp[u] = mxd[u] - dis[u] + 1;
  }
}
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++idx;
  sta[++stak] = u;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v])
      tarjan(v, u), low[u] = min(low[u], low[v]);
    else if (v != fa)
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    ++cnt;
    int v;
    do {
      v = sta[stak--];
      belong[v] = cnt;
    } while (v != u);
  }
}
void dosaka(int u, int fa) {
  int id = belong[u], siz = cir[id].size();
  Head[0] = Tail[0] = Head[1] = Tail[1] = 1;
  for (int i = 0; i < siz; i++) {
    g[i] = 1;
    for (int j = head[cir[id][i]]; j; j = e[j].nxt)
      if (belong[e[j].to] != id) g[i] = max(dp[e[j].to] + 1, g[i]);
  }
  for (int i = 1; i + i <= siz; i++) {
    while (Head[0] < Tail[0] &&
           g[i] + i >= g[q[0][Tail[0] - 1]] + q[0][Tail[0] - 1])
      Tail[0]--;
    q[0][Tail[0]++] = i;
  }
  for (int i = (siz + 1) / 2; i < siz; i++) {
    while (Head[1] < Tail[1] &&
           g[i] - i >= g[q[1][Tail[1] - 1]] - q[1][Tail[1] - 1])
      Tail[1]--;
    q[1][Tail[1]++] = i;
  }
  if (Head[0] < Tail[0]) ans[u] = max(ans[u], g[q[0][Head[0]]] + q[0][Head[0]]);
  if (Head[1] < Tail[1])
    ans[u] = max(ans[u], g[q[1][Head[1]]] + siz - q[1][Head[1]]);
  for (int i = 1; i < siz; i++) {
    int stp = cir[id][i], las = i - 1,
        lst = (i + (siz + 1) / 2 - 1 + siz) % siz;
    while (Head[1] < Tail[1] && q[1][Head[1]] == lst) Head[1]++;
    while (Head[0] < Tail[0] && q[0][Head[0]] == i) Head[0]++;
    while (Head[1] < Tail[1] &&
           g[q[1][Tail[1] - 1]] + (i + siz - q[1][Tail[1] - 1]) % siz <=
               g[las] + (i + siz - las) % siz)
      Tail[1]--;
    q[1][Tail[1]++] = las;
    while (Head[0] < Tail[0] &&
           g[q[0][Tail[0] - 1]] + (q[0][Tail[0] - 1] + siz - i) % siz <=
               g[lst] + (lst + siz - i) % siz)
      Tail[0]--;
    q[0][Tail[0]++] = lst;
    if (Head[0] < Tail[0])
      ans[stp] =
          max(ans[stp], g[q[0][Head[0]]] + (q[0][Head[0]] - i + siz) % siz);
    if (Head[1] < Tail[1])
      ans[stp] =
          max(ans[stp], g[q[1][Head[1]]] + (i + siz - q[1][Head[1]]) % siz);
  }
  for (int i = 0; i < siz; i++) {
    u = cir[id][i];
    int f1 = 1, f2 = 1;
    for (int j = head[u]; j; j = e[j].nxt) {
      int v = e[j].to;
      if (belong[v] == id) continue;
      if (dp[v] + 1 > f1)
        f2 = f1, f1 = dp[v] + 1;
      else if (dp[v] + 1 > f2)
        f2 = dp[v] + 1;
    }
    f1 = max(ans[u], f1);
    f2 = max(ans[u], f2);
    ans[u] = max(f1, ans[u]);
    for (int j = head[u]; j; j = e[j].nxt) {
      int v = e[j].to;
      if (belong[v] == id || v == fa) continue;
      int tmpu = dp[u];
      if (dp[v] + 1 == f1)
        dp[u] = f2;
      else
        dp[u] = f1;
      dosaka(v, u);
      dp[u] = tmpu;
    }
  }
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }
signed main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u);
    read(v);
    addEdge(u, v);
    addEdge(v, u);
  }
  bfs(1);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, 0);
  for (int i = 1; i <= n; i++) cir[belong[i]].push_back(i);
  for (int i = 1; i <= cnt; i++) sort(cir[i].begin(), cir[i].end(), cmp);
  dosaka(1, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i] - 1);
  puts("");
  return 0;
}
