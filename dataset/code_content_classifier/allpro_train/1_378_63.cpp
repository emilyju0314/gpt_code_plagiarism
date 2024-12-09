#include <bits/stdc++.h>
using namespace std;
const int MAXN = 900;
vector<int> neighbours[MAXN + 1];
vector<int> neighboursNoBridge[MAXN + 1];
vector<pair<int, int> > bridges;
bool used[MAXN + 1];
int timer, tin[MAXN + 1], fup[MAXN + 1];
void dfs(int node, int parent = -1) {
  used[node] = true;
  tin[node] = fup[node] = timer++;
  for (int child : neighbours[node]) {
    if (child == parent) continue;
    if (used[child])
      fup[node] = min(fup[node], tin[child]);
    else {
      dfs(child, node);
      fup[node] = min(fup[node], fup[child]);
      if (fup[child] > tin[node])
        bridges.push_back({node, child});
      else
        neighboursNoBridge[node].push_back(child),
            neighboursNoBridge[child].push_back(node);
    }
  }
}
void find_bridges(int n) {
  timer = 0;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) dfs(i);
  }
}
int groupIndex[MAXN + 1];
vector<int> groupDegree;
vector<int> groupNodes[MAXN + 1];
void dfsEnumerate(int node) {
  used[node] = true;
  groupIndex[node] = timer;
  groupNodes[timer].push_back(node);
  for (int child : neighboursNoBridge[node]) {
    if (!used[child]) dfsEnumerate(child);
  }
}
bool usedGroup[MAXN + 1];
vector<int> groupLeaves;
void dfsOrder(int node) {
  used[node] = true;
  int gr = groupIndex[node];
  if (!usedGroup[gr]) {
    usedGroup[gr] = true;
    if (groupDegree[gr] <= 1) groupLeaves.push_back(gr);
  }
  for (int child : neighbours[node]) {
    if (!used[child]) dfsOrder(child);
  }
}
void compress_graph(int n) {
  timer = 1;
  for (int i = 1; i <= n; ++i) used[i] = false;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) dfsEnumerate(i), timer++;
  }
}
void compress_graph2(int n) {
  groupDegree.resize(timer);
  for (pair<int, int> edge : bridges) {
    if (groupIndex[edge.first] != groupIndex[edge.second]) {
      ++groupDegree[groupIndex[edge.first]];
      ++groupDegree[groupIndex[edge.second]];
    }
  }
  for (int i = 1; i <= n; ++i) used[i] = false;
  dfsOrder(1);
}
int matrix[901][901];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    neighbours[a].push_back(b);
    neighbours[b].push_back(a);
    matrix[a][b] = matrix[b][a] = 1;
  }
  if (n == 2) {
    cout << -1 << endl;
    return 0;
  }
  find_bridges(n);
  compress_graph(n);
  int groupCount = timer - 1;
  if (groupCount == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (groupCount == 2) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (groupIndex[i] != groupIndex[j] && !matrix[i][j]) {
          cout << 1 << endl << i << ' ' << j << endl;
          return 0;
        }
      }
    }
  }
  compress_graph2(n);
  int leafPairs = (groupLeaves.size() + 1) / 2;
  cout << leafPairs << endl;
  for (int i = 0; i < leafPairs; ++i) {
    int leaf1 = groupLeaves[i], leaf2 = groupLeaves[i + groupLeaves.size() / 2];
    int node1 = -1, node2 = -1;
    bool found = false;
    for (int j : groupNodes[leaf1]) {
      for (int k : groupNodes[leaf2]) {
        if (!matrix[j][k]) {
          node1 = j, node2 = k;
          found = true;
          break;
        }
      }
      if (found) break;
    }
    cout << node1 << ' ' << node2 << endl;
  }
  return 0;
}
