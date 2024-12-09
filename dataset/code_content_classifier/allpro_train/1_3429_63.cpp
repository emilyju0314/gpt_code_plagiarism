#include <bits/stdc++.h>
const long long INF = (long long)1e18 + 123;
const int inf = (int)2e9 + 123;
const int mod = 1e9 + 7;
using namespace std;
int n, m, q;
int cnt = 0;
vector<int> g[100011];
vector<long double> t[100011], suff[100011];
long double ds[100011], d[100011], size[100011], mx[100011];
int f[100011];
void dfs(int v, int p = 0) {
  f[v] = cnt;
  size[f[v]]++;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
    mx[v] = max(mx[v], mx[to] + 1);
  }
  ds[v] = mx[v];
}
void calc(int v, long double fup = 0, int p = 0) {
  ds[v] = max(ds[v], fup);
  t[f[v]].push_back(ds[v]);
  d[f[v]] = max(d[f[v]], mx[v] + fup);
  long double m1 = 0, m2 = 0;
  for (auto to : g[v]) {
    if (to == p) continue;
    if (mx[to] + 1 >= m1) {
      m2 = m1;
      m1 = mx[to] + 1;
    } else if (mx[to] + 1 > m2)
      m2 = mx[to] + 1;
  }
  for (auto to : g[v]) {
    if (to == p) continue;
    if (mx[to] + 1 == m1)
      calc(to, max(fup, m2) + 1, v);
    else
      calc(to, max(fup, m1) + 1, v);
  }
  d[f[v]] = max(d[f[v]], m1 + m2);
}
map<int, long double> res[100011];
long double get(int x, int y, long double z) {
  long double br = max(d[x], d[y]) - z - 1;
  int l = 0, r = size[y] - 1, mx = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (t[y][mid] <= br) {
      mx = max(mx, mid);
      l = mid + 1;
    } else
      r = mid - 1;
  }
  long double ans = 0;
  ans += (long double)(mx + 1) * max(d[x], d[y]) + suff[y][mx + 1] +
         (size[y] - mx - 1) * (z + 1);
  return ans;
}
int main() {
  unsigned int FOR;
  asm("rdtsc" : "=A"(FOR));
  srand(FOR);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!f[i]) {
      cnt++;
      dfs(i);
      calc(i);
      sort(t[cnt].begin(), t[cnt].end());
      suff[cnt].resize(size[cnt]);
      suff[cnt][size[cnt] - 1] = t[cnt][size[cnt] - 1];
      for (int i = size[cnt] - 2; i >= 0; i--) {
        suff[cnt][i] = suff[cnt][i + 1] + t[cnt][i];
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    long double ans = 0;
    x = f[x];
    y = f[y];
    if (x == y) {
      cout << -1 << endl;
      continue;
    }
    if (res[x][y]) {
      cout << fixed << setprecision(6) << res[x][y] << endl;
      continue;
    }
    if (size[x] > size[y]) swap(x, y);
    for (int i = 0; i < size[x]; i++) {
      ans += get(x, y, t[x][i]);
    }
    res[x][y] = res[y][x] = ans / ((long double)size[x] * size[y]);
    cout << fixed << setprecision(6) << res[x][y] << endl;
  }
  return 0;
}
