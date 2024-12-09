#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
long long ar[500050], t[2000020];
pair<int, int> ran[500050];
long long lazy[2000020];
vector<int> g[500050];
vector<int> gp[500050];
void init(int b, int e, int node) {
  if (b == e) {
    t[node] = ar[b];
    return;
  }
  int mid = (b + e) / 2, l = 2 * node + 1, r = l + 1;
  init(b, mid, l);
  init(mid + 1, e, r);
  t[node] = min(t[l], t[r]);
}
void update(int b, int e, int node, int i, int j, int val) {
  if (b > e) return;
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  t[node] += lazy[node];
  if (b != e) {
    lazy[l] += lazy[node];
    lazy[r] += lazy[node];
  }
  lazy[node] = 0;
  if (b > j || e < i) return;
  if (b == e) {
    t[node] += val;
  } else if (b >= i && e <= j) {
    t[node] += val;
    lazy[l] += val;
    lazy[r] += val;
  } else {
    update(b, mid, l, i, j, val);
    update(mid + 1, e, r, i, j, val);
    t[node] = min(t[l], t[r]);
  }
}
long long query(int b, int e, int node, int i, int j) {
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  t[node] += lazy[node];
  if (b != e) {
    lazy[l] += lazy[node];
    lazy[r] += lazy[node];
  }
  lazy[node] = 0;
  if (b >= i && e <= j) return t[node];
  if (mid < i) return query(mid + 1, e, r, i, j);
  if (mid >= j) return query(b, mid, l, i, j);
  return min(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void dfs(int node, long long dis) {
  ran[node] = {node, node};
  if (g[node].size() == 0)
    ar[node] = dis;
  else {
    ar[node] = 1ll * MOD * MOD;
    for (int i = 0; i < g[node].size(); i++) {
      dfs(g[node][i], dis + gp[node][i]);
      ran[node].first = min(ran[node].first, ran[g[node][i]].first);
      ran[node].second = max(ran[node].second, ran[g[node][i]].second);
    }
  }
}
vector<pair<pair<int, int>, int>> que[500050];
long long res[500050];
int n;
void dfs1(int node) {
  for (auto cat : que[node]) {
    res[cat.second] = query(0, n - 1, 0, cat.first.first, cat.first.second);
  }
  int to;
  for (int i = 0; i < g[node].size(); i++) {
    to = g[node][i];
    update(0, n - 1, 0, ran[to].first, ran[to].second, -gp[node][i]);
    update(0, n - 1, 0, 0, ran[to].first - 1, gp[node][i]);
    update(0, n - 1, 0, ran[to].second + 1, n - 1, gp[node][i]);
    dfs1(to);
    update(0, n - 1, 0, ran[to].first, ran[to].second, gp[node][i]);
    update(0, n - 1, 0, 0, ran[to].first - 1, -gp[node][i]);
    update(0, n - 1, 0, ran[to].second + 1, n - 1, -gp[node][i]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  int a, b, c;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    g[a - 1].push_back(i);
    gp[a - 1].push_back(b);
  }
  dfs(0, 0);
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c;
    que[a - 1].push_back({{b - 1, c - 1}, i});
  }
  init(0, n - 1, 0);
  dfs1(0);
  for (int i = 0; i < q; i++) cout << res[i] << '\n';
  return 0;
}
