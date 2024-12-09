#include <bits/stdc++.h>
using namespace std;
int n, k, root, d[200005], h[200005], res[200005];
vector<int> a[200005];
void dfs(int u, int p) {
  int tmp = 0;
  for (int i = 0; i < (int)a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) continue;
    d[v] = d[u] + 1;
    dfs(v, u);
    tmp = max(tmp, h[v]);
  }
  h[u] = max(d[u], tmp);
}
void color(int u, int p, int cur, int step, bool diameter = true) {
  cur += step;
  if (cur > k)
    cur -= k;
  else if (cur <= 0)
    cur += k;
  res[u] = cur;
  int U = 0;
  for (int i = 0; i < (int)a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) continue;
    if (diameter) {
      if (U == 0 && h[v] == h[root]) {
        U = v;
        continue;
      }
      int len = h[v] - d[v] + 1;
      if (k > 2 && len + d[u] >= k && len + h[root] - d[u] + 1 >= k) {
        cout << "No";
        exit(0);
      } else if (len + d[u] >= k)
        color(v, u, cur, step, false);
      else
        color(v, u, cur, -step, false);
    } else
      color(v, u, cur, step, false);
  }
  if (U) color(U, u, cur, step);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 2; i <= n; i++)
    if (d[i] == h[1]) root = i;
  d[root] = 1;
  dfs(root, 0);
  color(root, 0, 0, 1);
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
  return 0;
}
