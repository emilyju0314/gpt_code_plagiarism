#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int sum[100010], l, r;
int tr[100010], f[100010], dp[100010];
void add(int x, int v) {
  for (; x <= m; x += (x & -x)) tr[x] = max(tr[x], v);
}
int query(int x) {
  int ans = 0;
  for (; x; x -= (x & -x)) ans = max(ans, tr[x]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l, &r), sum[l]++, sum[r + 1]--;
  for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= m; i++) sum[i]++;
  for (int i = 1; i <= m; i++) {
    f[i] = query(sum[i]) + 1;
    add(sum[i], f[i]);
  }
  memset(tr, 0, sizeof(tr));
  for (int i = m; i >= 1; i--) {
    dp[i] = query(sum[i]) + 1;
    add(sum[i], dp[i]);
  }
  for (int i = 1; i < m; i++) ans = max(ans, f[i] + dp[i + 1]);
  printf("%d", ans);
}
