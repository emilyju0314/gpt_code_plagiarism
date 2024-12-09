#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
struct note {
  int val, lz;
} t[N << 2];
int sum[55][N];
int dp[55][N];
void build(int rt, int l, int r) {
  if (l == r) {
    t[rt].val = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  t[rt].val = max(t[rt << 1].val, t[rt << 1 | 1].val);
}
void pushdown(int rt) {
  t[rt << 1].lz += t[rt].lz;
  t[rt << 1 | 1].lz += t[rt].lz;
  t[rt << 1].val += t[rt].lz;
  t[rt << 1 | 1].val += t[rt].lz;
  t[rt].lz = 0;
}
void update(int rt, int l, int r, int L, int R, int x) {
  if (L <= l && r <= R) {
    t[rt].lz += x;
    t[rt].val += x;
    return;
  }
  if (t[rt].lz) pushdown(rt);
  int mid = (l + r) >> 1;
  if (R <= mid)
    update(rt << 1, l, mid, L, R, x);
  else if (L > mid)
    update(rt << 1 | 1, mid + 1, r, L, R, x);
  else {
    update(rt << 1, l, mid, L, R, x);
    update(rt << 1 | 1, mid + 1, r, L, R, x);
  }
  t[rt].val = max(t[rt << 1].val, t[rt << 1 | 1].val);
}
int a[55][N];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  for (int i = 1; i <= m - k + 1; i++) {
    dp[1][i] =
        sum[1][i + k - 1] - sum[1][i - 1] + sum[2][i + k - 1] - sum[2][i - 1];
  }
  for (int i = 2; i <= n; i++) {
    memset(t, 0, sizeof(t));
    build(1, 1, m - k + 1);
    for (int j = 1; j <= m - k + 1; j++)
      update(1, 1, m - k + 1, j, j, dp[i - 1][j]);
    for (int j = 1; j <= k; j++) update(1, 1, m - k + 1, 1, j, -a[i][j]);
    for (int j = 1; j <= m - k + 1; j++) {
      dp[i][j] = t[1].val + sum[i][j + k - 1] - sum[i][j - 1] +
                 sum[i + 1][j + k - 1] - sum[i + 1][j - 1];
      if (j != m - k + 1) {
        update(1, 1, m - k + 1, max(1, j - k + 1), j, a[i][j]);
        update(1, 1, m - k + 1, j + 1, j + k, -a[i][j + k]);
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
  printf("%d\n", ans);
  return 0;
}
