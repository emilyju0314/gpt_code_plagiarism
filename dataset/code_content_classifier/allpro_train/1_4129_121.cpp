#include <bits/stdc++.h>
using namespace std;
struct base {
  int num[35];
  void insert(int v) {
    for (int i = 30; i >= 0; i--)
      if (v & (1 << i)) {
        if (!num[i]) {
          num[i] = v;
          return;
        } else
          v ^= num[i];
      }
  }
  int answer(int v) {
    for (int i = 30; i >= 0; i--)
      if ((v ^ num[i]) < v) v ^= num[i];
    return v;
  }
} orz;
struct node {
  int x, y, w;
  node(int X = 0, int Y = 0, int W = 0) : x(X), y(Y), w(W) {}
} road[800010 << 1];
vector<node> rp[800010 << 2];
void insert(int u, int l, int r, int L, int R, node w) {
  if (L <= l && r <= R) {
    rp[u].push_back(w);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) insert(u << 1, l, mid, L, R, w);
  if (R > mid) insert(u << 1 | 1, mid + 1, r, L, R, w);
}
int ql[800010], qr[800010], fa[800010], dep[800010], val[800010], ans[800010];
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
int find_dis(int x) { return x == fa[x] ? 0 : val[x] ^ find_dis(fa[x]); }
struct node2 {
  int x, y;
  bool o;
} sta[800010];
int topp;
void work(int u, int l, int r, base p, int ltop) {
  for (int i = 0; i < rp[u].size(); i++) {
    int x = rp[u][i].x, y = rp[u][i].y, w = rp[u][i].w;
    int hx = find(x), hy = find(y);
    w ^= find_dis(x) ^ find_dis(y);
    if (hx == hy)
      p.insert(w);
    else {
      if (dep[hx] > dep[hy]) {
        swap(hx, hy);
        swap(x, y);
      }
      node2 u = (node2){hx, hy, 0};
      fa[hx] = hy;
      val[hx] = w;
      if (dep[hx] == dep[hy]) {
        dep[hy]++;
        u.o = 1;
      }
      sta[++topp] = u;
    }
  }
  if (l == r)
    ans[l] = p.answer(find_dis(ql[l]) ^ find_dis(qr[l]));
  else {
    int mid = (l + r) >> 1;
    work(u << 1, l, mid, p, topp);
    work(u << 1 | 1, mid + 1, r, p, topp);
  }
  while (topp > ltop) {
    fa[sta[topp].x] = sta[topp].x;
    val[sta[topp].x] = 0;
    dep[sta[topp].y] -= sta[topp].o;
    topp--;
  }
}
map<pair<int, int>, int> mp;
int ld[800010], rd[800010];
signed main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  int cnt = m, tot = 1;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    mp[make_pair(x, y)] = i;
    ld[i] = 1;
    rd[i] = -1;
    road[i] = node(x, y, w);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int opt, x, y;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      int w;
      scanf("%d", &w);
      mp[make_pair(x, y)] = ++cnt;
      ld[cnt] = tot;
      rd[cnt] = -1;
      road[cnt] = node(x, y, w);
    } else if (opt == 2)
      rd[mp[make_pair(x, y)]] = tot - 1;
    else if (opt == 3) {
      ql[tot] = x;
      qr[tot] = y;
      tot++;
    }
  }
  tot--;
  for (int i = 1; i <= cnt; i++) {
    if (rd[i] == -1) rd[i] = tot;
    if (ld[i] <= rd[i]) insert(1, 1, tot, ld[i], rd[i], road[i]);
  }
  work(1, 1, tot, orz, 0);
  for (int i = 1; i <= tot; i++) printf("%d\n", ans[i]);
  return 0;
}
