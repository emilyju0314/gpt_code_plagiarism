#include <bits/stdc++.h>
using namespace std;
int ret = 0, n, m;
vector<int> adj[100010];
pair<int, int> f[100010];
int d[100010];
int gcd(int x, int y) {
  if (x > y) swap(x, y);
  return (!x) ? y : gcd(y % x, x);
}
void BFS(int x) {
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      } else if (d[u] + 1 - d[v] != 0)
        ret = gcd(ret, abs(1 + d[u] - d[v]));
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d %d", &f[i].first, &f[i].second);
  sort(f, f + m);
  for (int i = 0; i < m; i++)
    if (!i || f[i] > f[i - 1]) adj[f[i].first].push_back(f[i].second);
  memset(d, -1, sizeof(d));
  d[1] = 0;
  BFS(1);
  printf("%d\n", ret);
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (d[i] >= 0 && d[i] % ret == 0) v.push_back(i);
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf("%d", v[i]);
    if (i == v.size() - 1)
      printf("\n");
    else
      printf(" ");
  }
}
