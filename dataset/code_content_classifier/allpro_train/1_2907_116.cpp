#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, sum = 0;
bool visited[105];
int cost[105][105];
vector<int> ad[105];
void dfs(int src) {
  visited[src] = true;
  for (int i = 0; i < ad[src].size(); i++) {
    int v = ad[src][i];
    if (!visited[v]) {
      sum += cost[src][v];
      ans = max(ans, sum);
      dfs(v);
      sum -= cost[src][v];
    }
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    ad[u].push_back(v);
    ad[v].push_back(u);
    cost[u][v] = w;
    cost[v][u] = w;
  }
  dfs(0);
  printf("%d\n", ans);
  return 0;
}
