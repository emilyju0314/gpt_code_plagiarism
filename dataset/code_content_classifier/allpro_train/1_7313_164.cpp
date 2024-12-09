#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
void bfs(int size, int start, int end) {
  vector<int> v(size);
  fill(v.begin(), v.end(), 1000000);
  queue<int> q;
  v[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto it : graph[a]) {
      if (v[it] > v[a] + 1) {
        if (it == end) {
          cout << v[a] + 1;
          return;
        }
        v[it] = v[a] + 1;
        q.push(it);
      }
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int t, n, m, k, a, b, c, a1, a2, b1, b2;
  string s, l;
  cin >> n >> m;
  int q = max(2 * m, n);
  graph = vector<vector<int>>(q + 1);
  for (int i = 1; i <= q; i++) {
    if (i > 1) graph[i].push_back(i - 1);
    if (i * 2 <= q) graph[i].push_back(i * 2);
  }
  bfs(q + 1, n, m);
}
