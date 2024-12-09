#include <bits/stdc++.h>
using namespace std;
const int Max = 1e5 + 5;
vector<int> G[Max];
int c[Max];
int n, k;
vector<int> course;
vector<int> topo;
bool dfs(int u) {
  c[u] = -1;
  for (auto v : G[u]) {
    if (c[v] < 0) return false;
    if (!c[v] && !dfs(v)) return false;
  }
  c[u] = 1;
  topo.push_back(u);
  return true;
}
bool topoSort() {
  for (auto u : course)
    if (!c[u] && !dfs(u)) return false;
  return true;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; ++i) {
    int c_;
    scanf("%d", &c_);
    course.push_back(c_);
  }
  for (int i = 1; i <= n; ++i) {
    int d, from;
    scanf("%d", &d);
    for (int j = 1; j <= d; ++j) {
      scanf("%d", &from);
      G[i].push_back(from);
    }
  }
  if (topoSort()) {
    printf("%d\n", topo.size());
    for (auto i : topo) printf("%d ", i);
    printf("\n");
  } else
    printf("-1\n");
}
