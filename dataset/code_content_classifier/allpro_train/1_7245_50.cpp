#include <bits/stdc++.h>
using namespace std;
long long dist[1010][1010], cost[1010];
vector<pair<int, long long> > edges0[1010], edges1[1010];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    q;
void dij(int st) {
  dist[st][st] = 0;
  q.push(make_pair(0, st));
  while (!q.empty()) {
    if (q.top().first > dist[st][q.top().second]) {
      q.pop();
      continue;
    }
    pair<long long, int> u = q.top();
    q.pop();
    for (int i = 0; i < edges0[u.second].size(); i++)
      if (u.first + edges0[u.second][i].second <
          dist[st][edges0[u.second][i].first]) {
        dist[st][edges0[u.second][i].first] =
            u.first + edges0[u.second][i].second;
        q.push(make_pair(u.first + edges0[u.second][i].second,
                         edges0[u.second][i].first));
      }
  }
}
signed main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  while (m--) {
    int a, b;
    long long len;
    cin >> a >> b >> len;
    edges0[a].push_back(make_pair(b, len));
    edges0[b].push_back(make_pair(a, len));
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dist[i][j] = 1e17 + 100;
  for (int i = 1; i <= n; i++) dij(i);
  for (int i = 1; i <= n; i++) {
    long long t, c;
    cin >> t >> c;
    for (int j = 1; j <= n; j++)
      if (dist[i][j] <= t && j != i) {
        edges1[i].push_back(make_pair(j, c));
      }
  }
  for (int i = 1; i <= n; i++) cost[i] = 1e17 + 100;
  cost[x] = 0;
  q.push(make_pair(0, x));
  while (!q.empty()) {
    if (q.top().first > cost[q.top().second]) {
      q.pop();
      continue;
    }
    pair<long long, int> u = q.top();
    q.pop();
    for (int i = 0; i < edges1[u.second].size(); i++)
      if (u.first + edges1[u.second][i].second <
          cost[edges1[u.second][i].first]) {
        cost[edges1[u.second][i].first] = u.first + edges1[u.second][i].second;
        q.push(make_pair(cost[edges1[u.second][i].first],
                         edges1[u.second][i].first));
      }
  }
  if (cost[y] == 1e17 + 100)
    puts("-1");
  else
    cout << cost[y];
  return 0;
}
