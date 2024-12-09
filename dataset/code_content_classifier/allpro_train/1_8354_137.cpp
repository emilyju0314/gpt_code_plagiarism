#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
int n;
vector<int> g[maxn], v;
long long cost(int x) {
  int i, j;
  long long ans = 0, need = x - g[0].size();
  v.clear();
  for (i = 1; i < maxn; i++) {
    for (j = 0; j < g[i].size(); j++)
      if (g[i].size() - j >= x) {
        need--;
        ans += g[i][j];
      } else
        v.push_back(g[i][j]);
  }
  sort(v.begin(), v.end());
  for (i = 0; i < need; i++) ans += v[i];
  return ans;
}
int main() {
  int i, a, b;
  long long ans = inf;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
  }
  for (i = 0; i < maxn; i++) sort(g[i].begin(), g[i].end());
  int l, r, m1, m2;
  l = g[0].size();
  r = n;
  while (l < r) {
    m1 = (l + l + r) / 3;
    m2 = (l + r + r) / 3;
    if (cost(m1) > cost(m2)) {
      if (l == m1) break;
      l = m1;
    } else {
      if (r == m2) break;
      r = m2;
    }
  }
  for (i = l; i <= r; i++) ans = min(ans, cost(i));
  printf("%d\n", ans);
  return 0;
}
