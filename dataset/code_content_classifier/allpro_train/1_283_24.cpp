#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int b, long long int mod) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
  return pw(a * a % mod, b / 2, mod) % mod;
}
const long long int MAXN = 510;
const int INF = 1e9;
const long long int MOD = 1e9 + 7;
struct node {
  int u, v, turn;
};
int n, m, dist[MAXN][MAXN][2];
vector<int> adj[MAXN], A, B;
node par[MAXN][MAXN][2];
queue<node> q;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      dist[i][j][0] = dist[i][j][1] = INF;
    }
  }
  q.push(node{1, n, 0});
  dist[1][n][0] = 0;
  par[1][n][0] = {-1, -1, -1};
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int x = (u.turn == 0 ? u.u : u.v);
    for (int y : adj[x]) {
      node v = (u.turn == 0 ? node{y, u.v, 1} : node{u.u, y, 0});
      if (u.turn == 1 && v.u == v.v) continue;
      if (dist[v.u][v.v][v.turn] < INF) continue;
      dist[v.u][v.v][v.turn] = dist[u.u][u.v][u.turn] + 1;
      par[v.u][v.v][v.turn] = (u.turn == 0 ? u : par[u.u][u.v][u.turn]);
      q.push(v);
    }
  }
  if (dist[n][1][0] == INF) return cout << -1 << '\n', 0;
  node u = {n, 1, 0};
  while (u.u != -1) {
    A.push_back(u.u);
    B.push_back(u.v);
    u = par[u.u][u.v][u.turn];
  }
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  cout << A.size() - 1 << '\n';
  for (int u : A) cout << u << ' ';
  cout << '\n';
  for (int u : B) cout << u << ' ';
  cout << '\n';
  return 0;
}
