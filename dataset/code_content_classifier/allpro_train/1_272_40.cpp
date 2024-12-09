#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const long long int mod = 1e9 + 7;
const int inf = 1e9;
const int lg = 19;
int mn[4 * N], mx[2][4 * N], mx1[2][4 * N], mx2[2][4 * N], mx3[2][4 * N];
int n, q, ti = 0, par[N], H[N], h[N], st[N], fi[N];
bool k[N], lazy[4 * N];
vector<pair<int, int>> e;
vector<pair<int, bool>> adj[N];
void upd(int ind) {
  swap(mx[0][ind], mx[1][ind]);
  swap(mx1[0][ind], mx1[1][ind]);
  swap(mx2[0][ind], mx2[1][ind]);
  swap(mx3[0][ind], mx3[1][ind]);
  lazy[ind] ^= 1;
  return;
}
void merge(int i) {
  int lc = i * 2, rc = i * 2 + 1;
  mn[i] = min(mn[lc], mn[rc]);
  mx[0][i] = max(mx[0][lc], mx[0][rc]);
  mx1[0][i] = max(mx1[0][lc], mx1[0][rc]);
  mx1[0][i] = max(mx1[0][i], mx[0][lc] - 2 * mn[rc]);
  mx2[0][i] = max(mx2[0][lc], mx2[0][rc]);
  mx2[0][i] = max(mx2[0][i], mx[0][rc] - 2 * mn[lc]);
  mx3[0][i] = max(mx3[0][lc], mx3[0][rc]);
  mx3[0][i] = max(mx3[0][i], mx[0][lc] + mx2[0][rc]);
  mx3[0][i] = max(mx3[0][i], mx[0][rc] + mx1[0][lc]);
  mx[1][i] = max(mx[1][lc], mx[1][rc]);
  mx1[1][i] = max(mx1[1][lc], mx1[1][rc]);
  mx1[1][i] = max(mx1[1][i], mx[1][lc] - 2 * mn[rc]);
  mx2[1][i] = max(mx2[1][lc], mx2[1][rc]);
  mx2[1][i] = max(mx2[1][i], mx[1][rc] - 2 * mn[lc]);
  mx3[1][i] = max(mx3[1][lc], mx3[1][rc]);
  mx3[1][i] = max(mx3[1][i], mx[1][lc] + mx2[1][rc]);
  mx3[1][i] = max(mx3[1][i], mx[1][rc] + mx1[1][lc]);
  return;
}
void add(int l, int r, int b = 0, int e = ti, int ind = 1) {
  if (e <= l || b >= r) return;
  if (l <= b && e <= r) {
    upd(ind);
    return;
  }
  if (lazy[ind]) {
    upd(ind * 2);
    upd(ind * 2 + 1);
    lazy[ind] = false;
  }
  int mid = (b + e) / 2;
  add(l, r, b, mid, ind * 2);
  add(l, r, mid, e, ind * 2 + 1);
  merge(ind);
  return;
}
void build(int b = 0, int e = ti, int ind = 1) {
  if (b + 1 == e) {
    int x = k[b];
    mx1[x][ind] = mx2[x][ind] = -h[b];
    mx[x][ind] = mn[ind] = h[b];
    x = !k[b];
    mx[x][ind] = mx1[x][ind] = mx2[x][ind] = mx3[x][ind] = -inf;
    return;
  }
  int mid = (b + e) / 2;
  build(b, mid, ind * 2);
  build(mid, e, ind * 2 + 1);
  merge(ind);
}
void dfs(int u, int hh, bool b) {
  h[ti] = hh;
  k[ti] = b;
  st[u] = ti;
  ti++;
  for (auto x : adj[u]) {
    if (x.first != par[u]) {
      par[x.first] = u;
      dfs(x.first, hh + 1, b ^ x.second);
      h[ti] = hh;
      k[ti] = b;
      ti++;
    }
  }
  fi[u] = ti;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    bool w;
    cin >> x >> y >> w;
    x--;
    y--;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
    e.push_back({x, y});
  }
  dfs(0, 0, 0);
  build();
  cin >> q;
  while (q--) {
    int id;
    cin >> id;
    id--;
    int x = e[id].first;
    int y = e[id].second;
    if (x == par[y]) swap(x, y);
    add(st[x], fi[x]);
    cout << max(mx3[0][1], mx3[1][1]) << endl;
  }
  return 0;
}
