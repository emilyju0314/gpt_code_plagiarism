#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e5 + 20;
vector<pair<pair<int, int>, int> > f;
vector<pair<int, int> > g[N];
long long n, m, s, d[N], ans, l;
void dijkstra(int src) {
  set<pair<int, int> > q;
  d[src] = 0;
  q.insert(make_pair(0, src));
  while (q.size()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (auto u : g[v])
      if (d[u.first] > d[v] + u.second) {
        q.erase(make_pair(d[u.first], u.first));
        d[u.first] = d[v] + u.second;
        q.insert(make_pair(d[u.first], u.first));
      }
  }
}
bool check(pair<pair<int, int>, int> e, int r) {
  if (r <= 0 || r >= e.second) return 0;
  int t = min(d[e.first.first] + r, d[e.first.second] + e.second - r);
  return t == l;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(d, 31, sizeof d);
  cin >> n >> m >> s;
  for (int i = 0, v, u, w; i < m; i++) {
    cin >> v >> u >> w;
    g[v].push_back(make_pair(u, w));
    g[u].push_back(make_pair(v, w));
    f.push_back(make_pair(make_pair(v, u), w));
  }
  cin >> l;
  dijkstra(s);
  for (int i = 1; i <= n; i++)
    if (d[i] == l) ans++;
  for (auto e : f)
    if (min(d[e.first.first], d[e.first.second]) < l) {
      set<int> res;
      if (check(e, l - d[e.first.first])) res.insert(l - d[e.first.first]);
      if (check(e, e.second - (l - d[e.first.second])))
        res.insert(e.second - (l - d[e.first.second]));
      ans += res.size();
    }
  cout << ans << endl;
}
