#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
int n, m, k;
int dist[MAX][MAX];
void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        dist[i][j] = 1e9;
      }
    }
  }
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    dist[a][b] = d;
    dist[b][a] = d;
    edges.push_back({a, b});
  }
  floyd();
  int ans = INT_MAX;
  vector<pair<int, int>> couriers;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    couriers.push_back({a, b});
  }
  for (int i = 0; i < m; i++) {
    auto [a, b] = edges[i];
    int ss = 0;
    for (int j = 0; j < k; j++) {
      auto [x, y] = couriers[j];
      int op1 = dist[x][y];
      int op2 = dist[x][a] + dist[b][y];
      int op3 = dist[x][b] + dist[a][y];
      ss += min(op1, min(op2, op3));
    }
    ans = min(ans, ss);
  }
  cout << ans << endl;
  return 0;
}
