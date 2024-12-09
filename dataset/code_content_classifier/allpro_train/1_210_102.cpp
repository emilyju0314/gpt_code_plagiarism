#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, q, MOD, f[maxn], L[maxn], R[maxn], stp[maxn], lst[maxn], ans[maxn];
pair<int, int> a[maxn];
int main() {
  scanf("%d%d", &n, &MOD);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
  f[1] = 1;
  for (int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
  sort(a + 1, a + 1 + n);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d%d", &L[i], &R[i]);
  for (int i = 1; i <= n; i++) {
    int d = a[i].first % MOD, id = a[i].second;
    for (int j = 1; j <= q; j++)
      if (L[j] <= id && id <= R[j] && lst[j] != a[i].first)
        (ans[j] += f[++stp[j]] * d) %= MOD, lst[j] = a[i].first;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
