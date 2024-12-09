#include <bits/stdc++.h>
using namespace std;
vector<int> v[300030];
int ans[300030];
void dfs(int x) {
  int cnt = 0;
  for (int i = 0; i < v[x].size(); i++)
    if (ans[x] == ans[v[x][i]]) cnt++;
  if (cnt > 1) {
    ans[x] ^= 1;
    for (int i = 0; i < v[x].size(); i++)
      if (ans[x] == ans[v[x][i]]) dfs(v[x][i]);
  }
}
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = 1; i <= n; i++) printf("%d", ans[i]);
  return 0;
}
