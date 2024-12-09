#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 200002;
int t;
int n;
int a[N_MAX];
vector<int> edges[N_MAX];
vector<int> leaves;
vector<int> aux;
bool deleted[N_MAX];
int deg[N_MAX];
void eraseLeaves(int color) {
  while (leaves.empty() == false) {
    int u = leaves.back();
    leaves.pop_back();
    if (a[u] == 0 || a[u] == color) {
      deleted[u] = true;
      for (int v : edges[u])
        if (deleted[v] == false) {
          deg[v]--;
          if (deg[v] > 1) continue;
          if (a[v] == 0 || a[v] == color)
            leaves.push_back(v);
          else
            aux.push_back(v);
        }
    } else {
      deg[u]--;
      if (deg[u] > 1) continue;
      aux.push_back(u);
    }
  }
  for (int u : aux) leaves.push_back(u);
  aux.clear();
}
int solve(int color) {
  int answer = 1;
  for (int i = 1; i <= n; i++) {
    deleted[i] = false;
    deg[i] = edges[i].size();
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) leaves.push_back(i);
  eraseLeaves(color);
  color = 3 - color;
  while (leaves.empty() == false) {
    eraseLeaves(color);
    color = 3 - color;
    answer++;
  }
  return answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    cout << min(solve(1), solve(2)) << "\n";
    for (int i = 1; i <= n; i++) edges[i].clear();
  }
  return 0;
}
