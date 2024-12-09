#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
vector<int> p;
int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
vector<vector<pair<int, int> > > adj;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  p.assign(n, 0);
  adj.assign(n, vector<pair<int, int> >());
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    int t = 0;
    if (z == b) t = 1;
    adj[x].push_back(pair<int, int>(y, t));
    adj[y].push_back(pair<int, int>(x, t));
    if (t == 0) p[f(x)] = f(y);
  }
  map<int, int> comp;
  int sz = 0;
  for (int i = 0; i < n; i++) {
    if (comp.find(f(i)) == comp.end()) comp[f(i)] = sz++;
  }
  vector<vector<int> > cc(sz, vector<int>());
  for (int i = 0; i < n; i++) cc[comp[f(i)]].push_back(i);
  sz = 0;
  comp.clear();
  for (int i = 0; i < (int)cc.size(); i++) {
    if ((int)cc[i].size() > 3) comp[f(cc[i][0])] = sz++;
  }
  vector<vector<int> > dis(1 << sz, vector<int>(n, 1000000010));
  dis[0][0] = 0;
  priority_queue<pair<int, pair<int, int> >,
                 vector<pair<int, pair<int, int> > >,
                 greater<pair<int, pair<int, int> > > >
      pq;
  pq.push(pair<int, pair<int, int> >(0, pair<int, int>(0, 0)));
  while (!pq.empty()) {
    pair<int, pair<int, int> > front = pq.top();
    pq.pop();
    int mask = front.second.first;
    int u = front.second.second;
    if (front.first > dis[mask][u]) continue;
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = adj[u][j].first;
      int ty = adj[u][j].second;
      if (ty == 0) {
        int cost = dis[mask][u] + a;
        if (dis[mask][v] > cost) {
          dis[mask][v] = cost;
          pq.push(pair<int, pair<int, int> >(dis[mask][v],
                                             pair<int, int>(mask, v)));
        }
      } else {
        int cost = dis[mask][u] + b;
        if (f(u) != f(v)) {
          int vmask = mask;
          if (comp.find(f(v)) != comp.end()) {
            if (mask & (1 << comp[f(v)])) continue;
          }
          if (comp.find(f(u)) != comp.end()) {
            vmask |= (1 << comp[f(u)]);
          }
          if (dis[vmask][v] > cost) {
            dis[vmask][v] = cost;
            pq.push(pair<int, pair<int, int> >(dis[vmask][v],
                                               pair<int, int>(vmask, v)));
          }
        }
      }
    }
  }
  vector<int> dp(n, 1000000010);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << sz); j++) {
      dp[i] = min(dp[i], dis[j][i]);
    }
  }
  for (int i = 0; i < n; i++) cout << dp[i] << " ";
  cout << endl;
  return 0;
}
