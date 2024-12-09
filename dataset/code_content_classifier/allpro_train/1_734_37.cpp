#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[402][402];
int bfs(int cmp) {
  queue<pair<int, int> > q;
  q.push(make_pair(1, 0));
  int visitados[402];
  memset(visitados, 0, sizeof(visitados));
  while (!q.empty()) {
    pair<int, int> atual = q.front();
    q.pop();
    if (atual.first == n) return atual.second;
    if (visitados[atual.first]) continue;
    visitados[atual.first] = 1;
    for (int i = 1; i <= n; i++) {
      if (adj[atual.first][i] == cmp && !visitados[i])
        q.push(make_pair(i, atual.second + 1));
    }
  }
  return -1;
}
int main() {
  memset(adj, 0, sizeof(adj));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int in, in1;
    cin >> in >> in1;
    adj[in][in1] = 1;
    adj[in1][in] = 1;
  }
  int a = bfs(1), b = bfs(0);
  if (a != -1 && b != -1)
    cout << max(bfs(1), bfs(0)) << endl;
  else
    cout << -1 << endl;
}
