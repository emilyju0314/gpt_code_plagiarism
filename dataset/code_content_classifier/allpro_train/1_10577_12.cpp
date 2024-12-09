#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long ans = 1e9, n;
set<long long> adj[N];
long long a[N];
map<long long, long long> dist;
map<long long, long long> parent;
void bfs(long long s) {
  dist.clear();
  parent.clear();
  parent[s] = 0;
  dist[s] = 1;
  queue<long long> q;
  q.push(s);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    set<long long>::iterator it = adj[u].begin();
    for (; it != adj[u].end(); it++) {
      long long v = *(it);
      if (dist[v] == 0) {
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push(v);
      } else if (parent[u] != v)
        ans = min(ans, dist[u] + dist[v] - 1);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<long long> setBit[100];
  for (long long i = 0; i < 100; i++) setBit[i].clear();
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < 64; j++) {
      long long x = (1LL << j);
      if (a[i] & x) setBit[j].push_back(i);
    }
  }
  for (long long i = 0; i < 64; i++) {
    if (setBit[i].size() >= 3) return cout << 3, 0;
    if (setBit[i].size() == 2) {
      long long x = setBit[i][0];
      long long y = setBit[i][1];
      adj[x].insert(y);
      adj[y].insert(x);
    }
  }
  for (long long i = 1; i <= n; i++) bfs(i);
  if (ans == 1e9)
    cout << -1;
  else
    cout << ans;
}
