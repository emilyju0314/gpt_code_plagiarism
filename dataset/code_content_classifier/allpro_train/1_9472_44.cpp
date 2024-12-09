#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long double eps = 1e-10, pi = acos(-1);
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
vector<int> e[N];
int n, m, q, st[N], tp, fa[N], sz[N], sn[N];
long double fg[N];
vector<int> pf[N];
vector<long double> sg[N];
struct node {
  long double x, y;
  node operator+(const node &bb) const { return (node){x + bb.x, y + bb.y}; }
  node operator-(const node &bb) const { return (node){x - bb.x, y - bb.y}; }
  node operator*(const long double &bb) const { return (node){x * bb, y * bb}; }
  long double operator*(const node &bb) const { return x * bb.y - y * bb.x; }
  long double ang() { return atan2(y, x); }
} a[N], b, c;
void dfs(int x) {
  int nn = e[x].size();
  for (int i = 0; i < nn; ++i)
    if (e[x][i] == fa[x]) {
      swap(e[x][i], e[x][nn - 1]), e[x].pop_back(), --nn;
      break;
    }
  fg[x] = (a[fa[x]] - a[x]).ang();
  sort(e[x].begin(), e[x].end(), [&](int aa, int bb) {
    return (a[aa] - a[x]).ang() < (a[bb] - a[x]).ang();
  });
  sz[x] = 1;
  for (int i = 0; i < nn; ++i) {
    int y = e[x][i], nd = 0;
    if (!fa[y]) fa[y] = x, dfs(y), sz[x] += sz[y], nd = -sz[y];
    pf[x].push_back(nd);
    sg[x].push_back((a[y] - a[x]).ang());
  }
  for (int i = 0; i < nn; ++i) sg[x].push_back(sg[x][i] + pi * 2);
  int mm = pf[x].size();
  for (int i = 0; i < mm; ++i) pf[x].push_back(pf[x][i]);
  for (int i = 1; i < mm + mm; ++i) pf[x][i] += pf[x][i - 1];
  sn[x] = nn;
}
int qr2(long double gg, int x) {
  int l = 0, r = sg[x].size() - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (sg[x][mid] < gg - eps)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l - 1;
}
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= m; ++i) {
    int x = rd(), y = rd();
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) a[i].x = rd(), a[i].y = rd();
  int rt = 1;
  for (int i = 2; i <= n; ++i)
    if (a[rt].x > a[i].x) rt = i;
  a[n + 1].x = -2e9, a[n + 1].y = 0;
  fa[rt] = n + 1, dfs(rt);
  q = rd();
  while (q--) {
    tp = rd();
    for (int i = 1; i <= tp; ++i) st[i] = rd();
    st[tp + 1] = st[1], st[0] = st[tp];
    int sx = 1, ans = 0;
    for (int i = 2; i <= tp; ++i)
      if (a[st[sx]].x > a[st[i]].x + eps ||
          (fabs(a[st[sx]].x - a[st[i]].x) < eps &&
           fabs((a[st[sx]] - a[st[sx - 1]]) * (a[st[sx + 1]] - a[st[sx]])) <
               fabs((a[st[i]] - a[st[i - 1]]) * (a[st[i + 1]] - a[st[i]]))))
        sx = i;
    if ((a[st[sx]] - a[st[sx - 1]]) * (a[st[sx + 1]] - a[st[sx]]) < 0)
      reverse(st + 1, st + tp + 1), st[tp + 1] = st[1], st[0] = st[tp];
    for (int i = 1; i <= tp; ++i) {
      long double g1 = (a[st[i + 1]] - a[st[i]]).ang(),
                  g2 = (a[st[i - 1]] - a[st[i]]).ang();
      if (g1 > g2 + eps) g2 += pi * 2;
      if (!(fg[st[i]] > g1 - eps && fg[st[i]] < g2 + eps) &&
          !(fg[st[i]] > g1 + pi * 2 - eps && fg[st[i]] < g2 + pi * 2 + eps) &&
          !(fg[st[i]] > g1 - pi * 2 - eps && fg[st[i]] < g2 - pi * 2 + eps))
        ans += sz[st[i]];
      if (sn[st[i]]) {
        int zl = qr2(g1 - eps, st[i]), zr = qr2(g2 + eps * 2, st[i]);
        ans += pf[st[i]][sn[st[i]] - 1];
        if (zl < zr) ans -= pf[st[i]][zr] - ((~zl) ? pf[st[i]][zl] : 0);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
