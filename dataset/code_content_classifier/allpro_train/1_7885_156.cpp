#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 17;
int N, M, K;
vector<pair<int, pair<int, int> > > graph[maxn];
long long DP[maxn];
pair<int, int> ans[maxn];
vector<int> vx;
vector<pair<int, int> > ng[maxn];
inline void printans() {
  cout << vx.size() << endl;
  for (int v : vx) cout << v << " ";
  cout << endl;
  exit(0);
}
void DFS(int u) {
  if (vx.size() >= K) printans();
  for (auto v : ng[u])
    if (vx.size() < K)
      vx.push_back(v.second), DFS(v.first);
    else
      printans();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> M >> K;
  for (int i = 1; i <= M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    graph[x].push_back({z, {y, i}});
    graph[y].push_back({z, {x, i}});
  }
  memset(DP, 0x2F, sizeof DP);
  DP[1] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  pq.push({DP[1], 1});
  while (!pq.empty()) {
    long long dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dist != DP[u]) continue;
    for (auto v : graph[u])
      if (dist + v.first < DP[v.second.first]) {
        DP[v.second.first] = dist + v.first;
        ans[v.second.first] = {u, v.second.second};
        pq.push({DP[v.second.first], v.second.first});
      }
  }
  for (int i = 2; i <= N; i++) ng[ans[i].first].push_back({i, ans[i].second});
  DFS(1);
  printans();
  return 0;
}
