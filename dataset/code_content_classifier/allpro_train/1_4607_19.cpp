#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005], b[100005], f[22], F[22], u[22], m, dp[2222222],
    cnt[2222222], C;
void ope(int x) {
  dp[x] = 0;
  for (int i = 1; i <= 20; ++i) {
    if ((1 << i) & x) {
      int y = x ^ (1 << i);
      if (dp[y] == -1) ope(y);
      if (!(y & f[i])) dp[x] |= dp[y];
    }
  }
  if (dp[x]) C = max(C, cnt[x]);
}
void dfs(int x) {
  u[x] = 1;
  m |= (1 << x);
  for (int i = 1; i <= 20; ++i)
    if (!u[i] && (F[x] & (1 << i))) dfs(i);
}
int main() {
  for (int i = 1; i < 2222000; ++i) {
    if (i & 1)
      cnt[i] = cnt[i >> 1] + 1;
    else
      cnt[i] = cnt[i >> 1];
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      char c;
      scanf(" %c", &c);
      a[i] = c - 96;
    }
    for (int i = 1; i <= n; ++i) {
      char c;
      scanf(" %c", &c);
      b[i] = c - 96;
    }
    memset(f, 0, sizeof(f));
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= n; ++i)
      if (a[i] != b[i]) f[a[i]] |= (1 << b[i]), F[b[i]] |= (1 << a[i]);
    for (int i = 1; i <= 20; ++i) F[i] |= f[i];
    memset(u, 0, sizeof(u));
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= 20; ++i) {
      if (!u[i]) {
        m = 0;
        C = 0;
        dfs(i);
        ope(m);
        ans += cnt[m] * 2 - 1 - C;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
