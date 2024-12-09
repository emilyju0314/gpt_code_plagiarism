#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> v[n + 1];
  long long t1 = m;
  long long t2 = n;
  while (t1--) {
    long long a, b, w;
    cin >> a >> b >> w;
    v[a].push_back({b, w});
    v[b].push_back({a, w});
  }
  set<long long> sx[n + 1];
  long long i = 1;
  while (t2--) {
    long long k;
    cin >> k;
    while (k--) {
      long long x1;
      cin >> x1;
      sx[i].insert(x1);
    }
    i++;
  }
  multiset<pair<long long, long long>> s;
  s.insert({0, 1});
  long long vis[n + 1];
  long long dis[n + 1];
  memset(vis, -1, sizeof(vis));
  for (long long i = 2; i <= n; i++) dis[i] = 1e18;
  dis[1] = 0;
  while (!s.empty()) {
    pair<long long, long long> t = *s.begin();
    s.erase(s.begin());
    if (vis[t.second] == -1) {
      vis[t.second] = 1;
      long long time = 0;
      while (t.second != n &&
             sx[t.second].find(dis[t.second] + time) != sx[t.second].end())
        time++;
      dis[t.second] += time;
      for (long long i = 0; i < v[t.second].size(); i++) {
        long long x = i;
        if (dis[t.second] + v[t.second][x].second < dis[v[t.second][x].first]) {
          dis[v[t.second][x].first] = dis[t.second] + v[t.second][x].second;
          s.insert({dis[v[t.second][x].first], v[t.second][x].first});
        }
      }
    }
  }
  if (dis[n] == 1e18) {
    cout << -1;
    return 0;
  }
  cout << dis[n];
}
