#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
int leaf[N];
vector<int> graph[N];
void dfs(int u, int par) {
  if (graph[u].size() == 0) {
    leaf[u] = 1;
  }
  for (auto v : graph[u]) {
    if (v == par) continue;
    dfs(v, u);
    leaf[u] += leaf[v];
  }
}
int main() {
  int n;
  cin >> n;
  int aa;
  for (int i = 2; i <= n; i++) {
    cin >> aa;
    graph[aa].push_back(i);
  }
  dfs(1, -1);
  sort(leaf + 1, leaf + 1 + n);
  for (int i = 1; i <= n; i++) {
    cout << leaf[i] << " ";
  }
  cout << endl;
  return 0;
}
