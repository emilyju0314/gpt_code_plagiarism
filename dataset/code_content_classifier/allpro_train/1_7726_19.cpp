#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d, m, a[N], b[N], c[N], cnt1, cnt2;
int main() {
  scanf("%d%d%d", &n, &d, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    if (a[i] <= m)
      b[++cnt1] = a[i];
    else
      c[++cnt2] = a[i];
  sort(b + 1, b + cnt1 + 1, greater<int>());
  sort(c + 1, c + cnt2 + 1, greater<int>());
  long long ans = 0;
  int o = (n + d) / (d + 1);
  for (int i = o; i >= 0; i--) {
    if (n - (i * (d + 1)) > cnt1) break;
    long long res = 0;
    for (int j = 1; j <= i; j++) res += c[j];
    int z = min(n - ((i - 1) * (d + 1)) - 1, cnt1);
    for (int j = 1; j <= z; j++) res += b[j];
    ans = max(res, ans);
  }
  printf("%lld\n", ans);
  return 0;
}
