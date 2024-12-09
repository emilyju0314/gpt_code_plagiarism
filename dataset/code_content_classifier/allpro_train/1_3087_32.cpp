#include <bits/stdc++.h>
using namespace std;
long long int n, adj[2000][2000];
vector<pair<long long int, long long int> > v[100005], v2;
long long int d[2000][2000];
long long int dist[1005];
void dijk(long long int src) {
  for (long long int i = 0; i < 1005; i++) dist[i] = 3e9;
  priority_queue<pair<long long int, long long int> > que;
  que.push({src, 0});
  dist[src] = 0;
  while (que.size()) {
    long long int x = que.top().first, dis = que.top().second;
    que.pop();
    for (long long int i = 0, ln = v[x].size(); i < ln; ++i) {
      long long int y = v[x][i].first, _dis = v[x][i].second;
      if (dis + _dis < dist[y]) {
        dist[y] = dis + _dis;
        que.push({y, dist[y]});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, nb, x, y, mx = 0, m, s, t;
  for (i = 0; i <= 1005; i++)
    for (j = 0; j <= 1005; j++) adj[i][j] = 0;
  cin >> n >> m >> s >> t;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back({y, 1});
    v[y].push_back({x, 1});
    adj[x][y] = 1;
    adj[y][x] = 1;
  }
  for (i = 1; i <= n; i++) {
    dijk(i);
    for (j = 1; j <= n; j++) {
      d[i][j] = dist[j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      if (!adj[i][j] && i != j) {
        v2.push_back({i, j});
        adj[i][j] = 1;
        adj[j][i] = 1;
      }
  }
  nb = 0;
  for (i = 0; i < v2.size(); i++) {
    x = v2[i].first;
    y = v2[i].second;
    if (d[s][t] > d[s][x] + 1 + d[y][t] || d[s][t] > d[s][y] + 1 + d[x][t])
      nb++;
  }
  cout << v2.size() - nb;
}
