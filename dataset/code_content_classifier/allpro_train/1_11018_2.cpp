#include <bits/stdc++.h>
using namespace std;
const int maxn = 7e5 + 5;
const int mod = 1e9 + 7;
int n, m, q;
int p[maxn], u[300010], v[300010], vis[300010], fa[maxn], op[500010][2],
    sz[maxn], boss[500010];
int pos[maxn], dfn[maxn], tot;
struct node {
  int w, pos;
} t[maxn << 2];
vector<int> G[maxn];
int fid(int x) { return x == fa[x] ? x : fa[x] = fid(fa[x]); }
void dfs(int u) {
  pos[u] = ++tot;
  dfn[tot] = u;
  sz[u] = 1;
  for (int v : G[u]) dfs(v), sz[u] += sz[v];
}
void push_up(int rt) {
  if (t[rt << 1].w > t[rt << 1 | 1].w)
    t[rt] = t[rt << 1];
  else
    t[rt] = t[rt << 1 | 1];
}
void build(int rt, int l, int r) {
  t[rt].w = t[rt].pos = 0;
  if (l == r) {
    t[rt].w = p[dfn[l]];
    t[rt].pos = l;
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  push_up(rt);
}
void upd(int rt, int l, int r, int z) {
  if (l == r && r == z) {
    t[rt].w = 0;
    return;
  }
  int mid = l + r >> 1;
  if (z <= mid)
    upd(rt << 1, l, mid, z);
  else
    upd(rt << 1 | 1, mid + 1, r, z);
  push_up(rt);
}
node ask(int rt, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[rt];
  int mid = l + r >> 1;
  node f1, f2;
  f1.w = f2.w = f1.pos = f2.pos = 0;
  if (ql <= mid) f1 = ask(rt << 1, l, mid, ql, qr);
  if (qr > mid) f2 = ask(rt << 1 | 1, mid + 1, r, ql, qr);
  if (f1.w > f2.w)
    return f1;
  else
    return f2;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u[i], &v[i]);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &op[i][0], &op[i][1]);
    if (op[i][0] == 2) vis[op[i][1]] = 1;
  }
  for (int i = 1; i <= n + q; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    if (vis[i]) continue;
    int fx = fid(u[i]), fy = fid(v[i]);
    if (fx != fy) {
      fa[fx] = fy;
      G[fy].push_back(fx);
    }
  }
  for (int i = q; i >= 1; i--) {
    if (op[i][0] == 2) {
      int x = op[i][1];
      int fx = fid(u[x]), fy = fid(v[x]);
      if (fx != fy) {
        n++;
        G[n].push_back(fx);
        G[n].push_back(fy);
        fa[fx] = n;
        fa[fy] = n;
      }
    } else
      boss[i] = fid(op[i][1]);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[pos[i]]) {
      dfs(fid(i));
    }
  }
  build(1, 1, tot);
  for (int i = 1; i <= q; i++) {
    if (op[i][0] == 1) {
      node x = ask(1, 1, tot, pos[boss[i]], pos[boss[i]] + sz[boss[i]] - 1);
      if (x.w > 0) upd(1, 1, tot, x.pos);
      printf("%d\n", x.w);
    }
  }
  return 0;
}
