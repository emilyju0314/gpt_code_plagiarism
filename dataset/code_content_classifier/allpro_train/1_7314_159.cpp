#include <bits/stdc++.h>
using namespace std;
struct edge {
  int other;
  int other_idx;
  bool used;
  int id;
  edge(int other, int other_idx, int id)
      : id(id), other(other), other_idx(other_idx), used(false) {}
};
void dfs_eulerian(vector<vector<edge>>& g, vector<int>& indices,
                  vector<pair<int, bool>>& ans, int node) {
  while (indices[node] < g[node].size()) {
    edge& e = g[node][indices[node]];
    if (!e.used) {
      e.used = true;
      g[e.other][e.other_idx].used = true;
      ++indices[node];
      dfs_eulerian(g, indices, ans, e.other);
      ans.push_back(make_pair(e.id, node < e.other));
    } else {
      ++indices[node];
    }
  }
}
int find_idx(map<int, int>& m, int x) {
  if (m.find(x) == m.end()) {
    int next = m.size();
    return m[x] = next;
  }
  return m[x];
}
vector<vector<edge>> constructGraph(int& N) {
  int x, y;
  int a_x, a_y, b_x, b_y, m_x, m_y;
  cin >> N;
  vector<vector<edge>> g(N * 2);
  map<int, int> unique_x, unique_y;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    int u_x = find_idx(unique_x, x);
    int u_y = find_idx(unique_y, y) + N;
    g[u_x].push_back(edge(u_y, g[u_y].size(), i));
    g[u_y].push_back(edge(u_x, g[u_x].size() - 1, i));
  }
  return g;
}
int getStartingNode(vector<vector<edge>>& g) {
  for (int i = 0; i < g.size(); ++i) {
    if (g[i].size() % 2 == 1) {
      return i;
    }
  }
  return 0;
}
int main() {
  int T;
  int N;
  vector<vector<edge>> g = constructGraph(N);
  int dummy = 2 * N;
  g.push_back(vector<edge>());
  for (int i = 0; i < g.size(); ++i) {
    if (g[i].size() % 2 == 1) {
      g[i].push_back(edge(dummy, g[dummy].size(), -1));
      g[dummy].push_back(edge(i, g[i].size() - 1, -1));
    }
  }
  vector<int> indices(g.size(), 0);
  vector<pair<int, bool>> ans;
  for (int i = 0; i < g.size(); ++i) {
    if (indices[i] != g[i].size()) {
      dfs_eulerian(g, indices, ans, i);
    }
  }
  vector<bool> label(N);
  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i].first == -1) continue;
    label[ans[i].first] = ans[i].second;
  }
  for (int i = 0; i < N; ++i) {
    cout << (label[i] ? 'r' : 'b');
  }
  cout << endl;
  return 0;
}
