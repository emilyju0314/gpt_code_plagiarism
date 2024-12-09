#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
int w[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  int u, v, c;
  double ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &c);
    ans = max(ans, (double)(w[u] + w[v]) / c);
  }
  printf("%.9lf\n", ans);
  return 0;
}
