#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
long long res, sum, num[maxn][25][2], v[maxn];
vector<int> edge[maxn];
void dfs(int u, int fa) {
  int w = v[u];
  res += w;
  for (int i = 1; i <= 22; i++) {
    num[u][i][1 & (w >> (i - 1))] = 1;
    num[u][i][1 & (w >> (i - 1)) ^ 1] = 0;
  }
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == fa) continue;
    dfs(v, u);
    for (int j = 1; j <= 22; j++) {
      res += ((num[u][j][0] * num[v][j][1] + num[u][j][1] * num[v][j][0])
              << (j - 1));
    }
    for (int j = 1; j <= 22; j++) {
      num[u][j][1 & (w >> (j - 1)) ^ 0] += num[v][j][0];
      num[u][j][1 & (w >> (j - 1)) ^ 1] += num[v][j][1];
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%I64d", &v[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  res = 0;
  dfs(1, -1);
  printf("%I64d\n", res);
  return 0;
}
