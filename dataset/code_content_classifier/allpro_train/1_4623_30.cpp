#include <bits/stdc++.h>
const int N = 2505;
int a[N][N], up[N], down[N], n, m, k;
long long ans;
char c;
int cal(int l1, int r1, int l2, int r2, int type) {
  if (type) std::swap(l1, l2), std::swap(r1, r2);
  return a[r1][r2] - a[l1 - 1][r2] - a[r1][l2 - 1] + a[l1 - 1][l2 - 1];
}
void solve(int l1, int r1, int l2, int r2, int type) {
  if (l1 > r1 || l2 > r2) return;
  if (r2 - l2 > r1 - l1) std::swap(l1, l2), std::swap(r1, r2), type ^= 1;
  int mid = (l1 + r1) >> 1;
  for (int i = l2; i <= r2; i++) {
    for (int j = 0; j <= k; j++) up[j] = l1, down[j] = r1;
    for (int j = i; j <= r2; j++) {
      for (int p = 0; p <= k; p++) {
        while (cal(up[p], mid, i, j, type) > p) up[p]++;
        while (cal(mid + 1, down[p], i, j, type) > p) down[p]--;
      }
      for (int p = 0; p <= k; p++)
        ans += 1ll * ((p ? up[p - 1] : mid + 1) - up[p]) * 1ll *
               (down[k - p] - ((k - p) ? down[k - p - 1] : mid - 1));
    }
  }
  solve(l1, mid - 1, l2, r2, type), solve(mid + 1, r1, l2, r2, type);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      c = getchar();
      while (c != '0' && c != '1') c = getchar();
      a[i][j] = c - '0';
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
  solve(1, n, 1, m, 0);
  printf("%lld\n", ans);
}
