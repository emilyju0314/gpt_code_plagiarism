#include <bits/stdc++.h>
using namespace std;
void s_y() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<vector<int>> adjtr(401);
vector<vector<int>> adjbus(401);
vector<int> dist(401, 0);
int shortest_path_tr(int src, int dest) {
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child : adjtr[node]) {
      if (dist[node] + 1 < dist[child]) {
        dist[child] = dist[node] + 1;
        q.push(child);
      }
    }
  }
  return dist[dest];
}
int shortest_path_bus(int src, int dest) {
  queue<int> q;
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int child : adjbus[node]) {
      if (dist[node] + 1 < dist[child]) {
        dist[child] = dist[node] + 1;
        q.push(child);
      }
    }
  }
  return dist[dest];
}
int main() {
  s_y();
  for (int i = 0; i <= 400; i++) {
    dist[i] = 1e9;
  }
  int n, m;
  cin >> n >> m;
  bool b = true;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adjtr[u].push_back(v);
    adjtr[v].push_back(u);
    if (u == 1 && v == n || u == n && v == 1) {
      b = false;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) {
      if (i != j) {
        int f = 0;
        for (int c : adjtr[i]) {
          if (c == j) {
            f = 1;
          }
        }
        if (f == 0) {
          adjbus[i].push_back(j);
          adjbus[j].push_back(i);
        }
      }
    }
  }
  if (b == true) {
    if (shortest_path_tr(1, n) < 1000000000) {
      cout << shortest_path_tr(1, n) << endl;
    } else {
      cout << "-1\n";
    }
  } else {
    if (shortest_path_bus(1, n) < 1000000000) {
      cout << shortest_path_bus(1, n) << endl;
    } else {
      cout << "-1\n";
    }
  }
}
