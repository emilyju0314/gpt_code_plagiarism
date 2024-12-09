#include <bits/stdc++.h>
using namespace std;
long long p[1000010], a[1000010];
int pr[2][1000010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  p[0] = 1;
  for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * 37;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    pr[0][i] = u, pr[1][i] = v;
    a[u] += p[v], a[v] += p[u];
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int u = pr[0][i], v = pr[1][i];
    if (a[u] + p[u] == a[v] + p[v]) ans++;
  }
  sort(a + 1, a + n + 1);
  long long sum = 0;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i - 1])
      ans += ++sum;
    else
      sum = 0;
  }
  printf("%I64d\n", ans);
  return 0;
}
