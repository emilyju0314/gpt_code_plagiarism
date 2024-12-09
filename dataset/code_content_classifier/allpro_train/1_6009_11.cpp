#include <bits/stdc++.h>
using namespace std;
int dp[26][(1 << 13) + 10][14];
int a[30];
int cnt(int x) {
  int res = 0;
  while (x) {
    res += x & 1;
    x >>= 1;
  }
  return res;
}
int lst;
int calc(int ones, int lef, int cur) {
  if (ones < 0) return false;
  int &res = dp[ones][lef][cur];
  if (res != -1) return res;
  if (cur == lst - 1) {
    int sum = ones;
    for (int i = 0; i < cur; i++)
      if (lef & (1 << i)) sum += a[i];
    if (cnt(lef) - 1 + ones >= 2)
      res = (sum + 1 == a[cur]);
    else
      res = 0;
    return res;
  }
  res = false;
  int msk = ((1 << cur) - 1) & lef;
  for (int x = msk; x > 0; x = (x - 1) & msk) {
    int sum = 1;
    for (int i = 0; i < cur; i++)
      if (x & (1 << i)) sum += a[i];
    if (sum > a[cur]) continue;
    int take_ones = a[cur] - sum;
    if (take_ones + cnt(x) >= 2)
      res = res || calc(ones - take_ones, lef & (~x), cur + 1);
  }
  int take_ones = a[cur] - 1;
  if (take_ones >= 2) res = res || calc(ones - take_ones, lef, cur + 1);
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int ones = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1)
      ones++;
    else
      a[lst++] = x;
  }
  if (n == 1 && ones) return puts("YES"), 0;
  sort(a, a + lst);
  memset(dp, -1, sizeof dp);
  int res = 1;
  res = res && lst && a[lst - 1] == n && ones >= lst;
  res = res && calc(ones, (1 << lst) - 1, 0);
  if (res)
    puts("YES");
  else
    puts("NO");
  return 0;
}
