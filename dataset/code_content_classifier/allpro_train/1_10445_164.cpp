#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y, pos, mx, tmp, dd;
int dep[100005], rt[100005], d[100005], dia[100005];
vector<int> v[100005], w[100005];
vector<long long> cnt[100005], sum[100005];
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
void dfs(int vtx, int par, int root) {
  dep[vtx] = dep[par] + 1;
  rt[vtx] = root;
  if (mx < dep[vtx]) mx = dep[pos = vtx];
  chkmax(d[vtx], dep[vtx] - 1);
  for (int i = 0; i < v[vtx].size(); i++) {
    int u = v[vtx][i];
    if (u == par) continue;
    dfs(u, vtx, root);
  }
}
void dfs_count(int vtx, int par, int root) {
  cnt[root][d[vtx]]++, sum[root][d[vtx]] += d[vtx], w[root].push_back(vtx);
  for (int i = 0; i < v[vtx].size(); i++) {
    int u = v[vtx][i];
    if (u == par) continue;
    dfs_count(u, vtx, root);
  }
}
void init() {
  for (int i = 1; i <= n; i++) {
    if (dep[i]) continue;
    mx = 0, pos = 0;
    dfs(i, 0, i);
    tmp = pos, pos = 0, mx = 0;
    dfs(tmp, 0, i);
    tmp = pos, pos = 0, mx = 0;
    dfs(tmp, 0, i);
    dia[i] = mx - 1;
    cnt[i].resize(mx), sum[i].resize(mx);
    dfs_count(i, 0, i);
    for (int j = mx - 2; j >= 0; j--) {
      cnt[i][j] += cnt[i][j + 1], sum[i][j] += sum[i][j + 1];
    }
  }
}
long long tot;
map<pair<int, int>, double> ans;
int main() {
  scanf("%d %d %d", &n, &m, &q);
  while (m--) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  init();
  while (q--) {
    scanf("%d %d", &x, &y);
    x = rt[x], y = rt[y];
    if (w[x].size() > w[y].size() || w[x].size() == w[y].size() && x > y)
      swap(x, y);
    if (x == y) {
      printf("-1\n");
      continue;
    }
    if (ans.count(make_pair(x, y))) {
      printf("%.8lf\n", ans[make_pair(x, y)]);
      continue;
    }
    tot = 0;
    dd = max(dia[x], dia[y]);
    for (int i = 0; i < w[x].size(); i++) {
      int u = w[x][i];
      long long cntt = cnt[y].size() > (dd - d[u]) ? cnt[y][dd - d[u]] : 0;
      long long summ = sum[y].size() > (dd - d[u]) ? sum[y][dd - d[u]] : 0;
      tot += (d[u] + 1) * cntt + summ + 1ll * dd * (w[y].size() - cntt);
    }
    printf("%.8lf\n",
           ans[pair<int, int>(x, y)] = 1.0 * tot / w[x].size() / w[y].size());
  }
}
