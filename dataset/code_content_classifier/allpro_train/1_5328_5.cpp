#include <bits/stdc++.h>
using namespace std;
int read() {
  int r = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r * f;
}
int n, m, Q;
int R;
int rotate(int element) {
  element = (element + R) % n;
  if (element == 0) {
    element = n;
  }
  return element;
}
struct data {
  int to, nxt;
};
int lg[300300], ll;
int bel[300300];
struct Graph {
  data mp[600600];
  int head[300300], cnt;
  void link(int x, int y) {
    mp[++cnt].to = y;
    mp[cnt].nxt = head[x];
    head[x] = cnt;
  }
  void add(int x, int y) { link(x, y), link(y, x); }
  int dfn[300300], clk;
  int low[300300];
  int st[300300], ts;
  int col[300300], tcol;
  int e[300300][2], te;
  void Tarjan(int x, int fa, int fi) {
    low[x] = dfn[x] = ++clk;
    st[++ts] = x;
    int v;
    for (int i = head[x]; i; i = mp[i].nxt)
      if (fi != i && fi != (i ^ 1)) {
        v = mp[i].to;
        if (!dfn[v])
          Tarjan(v, x, i), low[x] = min(low[x], low[v]);
        else
          low[x] = min(low[x], dfn[v]);
      }
    if (low[x] == dfn[x]) {
      tcol++;
      if (fa) e[++te][0] = x, e[te][1] = fa;
      while (st[ts + 1] != x) {
        st[ts + 1] = 0;
        col[st[ts]] = tcol, ts--;
      }
      st[ts + 1] = 0;
    }
  }
  int f[300300][22];
  int dep[300300];
  void dfs(int x, int r) {
    dfn[x] = ++clk;
    bel[x] = r;
    dep[x] = dep[f[x][0]] + 1;
    for (int i = 1; i <= 20; ++i) f[x][i] = f[f[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = mp[i].nxt)
      if (mp[i].to != f[x][0]) {
        f[mp[i].to][0] = x;
        dfs(mp[i].to, r);
      }
  }
  void rebuild() {
    memset(head, 0, sizeof(head));
    cnt = 0;
    int x, y;
    for (int i = 1; i <= te; ++i) add(col[e[i][0]], col[e[i][1]]);
    memset(dfn, 0, sizeof(dfn));
    clk = 0;
    for (int i = 1; i <= tcol; ++i)
      if (!dfn[i]) dfs(i, i);
  }
  int LCA(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    while (dep[y] != dep[x]) y = f[y][lg[dep[y] - dep[x]]];
    if (x == y) return x;
    for (int i = 20; i >= 0; --i)
      if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
  }
} g1, g2;
int ni, mi;
int p[300300], tp;
int ed[300300][2], ted;
bool book[300300];
int nd[300300], tnd;
bool cmp(int a, int b) { return g1.dfn[a] < g1.dfn[b]; }
int sta[300300], top;
int ext[300300], tex;
void build_vtree() {
  for (int i = 1; i <= tnd; ++i)
    if (!book[bel[nd[i]]]) book[bel[nd[i]]] = 1, nd[++tnd] = bel[nd[i]];
  sort(nd + 1, nd + tnd + 1, cmp);
  int x, lca;
  for (int i = 1, j; i <= tnd; i = j) {
    sta[top = 1] = nd[i];
    for (j = i + 1; bel[nd[j]] == bel[nd[i]] && j <= tnd; ++j) {
      x = nd[j];
      lca = g1.LCA(sta[top], x);
      if (!book[lca]) book[lca] = 1, ext[++tex] = lca;
      if (lca == sta[top]) {
        sta[++top] = x;
        continue;
      }
      while (g1.dep[sta[top - 1]] > g1.dep[lca]) {
        g2.add(sta[top], sta[top - 1]);
        top--;
      }
      g2.add(sta[top], lca);
      top--;
      if (sta[top] != lca) sta[++top] = lca;
      sta[++top] = x;
    }
    while (top > 1) {
      g2.add(sta[top], sta[top - 1]);
      top--;
    }
    top = 0;
  }
}
void reset() {
  int x;
  g2.cnt = 1;
  g2.tcol = g2.ts = g2.clk = g2.te = 0;
  for (int i = 1; i <= tnd; ++i) {
    x = nd[i];
    g2.head[x] = g2.dfn[x] = g2.low[x] = g2.col[x] = 0;
    book[x] = 0;
  }
  for (int i = 1; i <= tex; ++i) {
    x = ext[i];
    g2.head[x] = g2.dfn[x] = g2.low[x] = g2.col[x] = 0;
    book[x] = 0;
  }
  tex = 0;
}
int main() {
  n = read(), m = read(), Q = read();
  for (int i = 1; i <= n; ++i) lg[i] = (i == (1 << (ll + 1))) ? ++ll : ll;
  int xx, yy;
  g1.cnt = 1;
  for (int i = 1; i <= m; ++i) {
    xx = read(), yy = read();
    g1.link(xx, yy);
    g1.link(yy, xx);
  }
  for (int i = 1; i <= n; ++i)
    if (!g1.dfn[i]) g1.Tarjan(i, 0, 0);
  g1.rebuild();
  g2.cnt = 1;
  int ID = 0;
  while (Q--) {
    ID++;
    ni = read(), mi = read();
    tnd = 0;
    ted = 0;
    tp = 0;
    for (int i = 1; i <= ni; ++i) {
      xx = rotate(read());
      xx = g1.col[xx];
      if (book[xx]) continue;
      book[xx] = 1;
      nd[++tnd] = xx;
      p[++tp] = xx;
    }
    for (int i = 1; i <= mi; ++i) {
      xx = rotate(read());
      yy = rotate(read());
      xx = g1.col[xx];
      yy = g1.col[yy];
      if (xx == yy) continue;
      ed[++ted][0] = xx;
      ed[ted][1] = yy;
      if (!book[xx]) book[xx] = 1, nd[++tnd] = xx;
      if (!book[yy]) book[yy] = 1, nd[++tnd] = yy;
    }
    build_vtree();
    for (int i = 1; i <= ted; ++i) g2.add(ed[i][0], ed[i][1]);
    for (int i = 1; i <= tnd; ++i)
      if (!g2.dfn[nd[i]]) g2.Tarjan(nd[i], 0, 0);
    int fl = 1;
    for (int i = 1; i <= tp; ++i)
      if (g2.col[p[i]] != g2.col[p[1]]) {
        fl = 0;
        break;
      }
    puts(fl ? "YES" : "NO");
    R += fl * ID;
    R %= n;
    reset();
  }
  return 0;
}
