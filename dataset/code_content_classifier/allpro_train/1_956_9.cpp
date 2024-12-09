#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 1e9 + 7;
int a[maxn], ans[maxn];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int res = m;
  for (int i = 1; i <= n; i++) {
    if (res > a[i]) {
      res -= a[i];
      ans[i] = 0;
    } else {
      a[i] -= res;
      ans[i]++;
      res = m - a[i] % m;
      ans[i] += a[i] / m;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
