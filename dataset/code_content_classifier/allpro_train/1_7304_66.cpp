#include <bits/stdc++.h>
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
using namespace std;
constexpr int inf = 1e9 - 5, base = 541;
constexpr int mod = 1e8, N = 1e6 + 7, M = 1e4 + 77;
long long a[N];
int c[N], mark[N], vis[M];
long long dis[N];
set<pair<int, int> > s;
vector<pair<int, long long> > g[M];
void dij() {
  memset(dis, 127, sizeof dis);
  set<pair<int, long long> > o;
  dis[0] = 0;
  o.insert({0, 0});
  while (!o.empty()) {
    pair<int, long long> x = *o.begin();
    o.erase(o.begin());
    for (auto i : g[x.second])
      if (dis[i.first] > dis[x.second] + i.second) {
        o.erase({dis[i.first], i.first});
        dis[i.first] = dis[x.second] + i.second;
        o.insert({dis[i.first], i.first});
      }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long h;
  int n, m, k;
  cin >> h >> n >> m >> k;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> a[i] >> c[i];
    a[i]--;
    if (a[i] % k == 0) mark[i] = 1, s.insert({-c[i], i});
  }
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      long long x;
      cin >> x;
      for (int i = 0; i < k; i++) g[i].push_back({(i + x) % k, x});
      dij();
      for (int i = 0; i < n; i++)
        if (!mark[i] && dis[a[i] % k] <= a[i])
          s.insert({-c[i], i}), mark[i] = true;
    }
    if (t == 2) {
      long long x, y;
      cin >> x >> y;
      x--;
      if (mark[x] == 1) s.erase({-c[x], x});
      c[x] = c[x] - y;
      if (mark[x] == 1) s.insert({-c[x], x});
    }
    if (t == 3) {
      if (s.empty())
        cout << "0\n";
      else {
        pair<int, int> x = *s.begin();
        s.erase(s.begin());
        mark[x.second] = -1;
        cout << -x.first << '\n';
      }
    }
  }
}
