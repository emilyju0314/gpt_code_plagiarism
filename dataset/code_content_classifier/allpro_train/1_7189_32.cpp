#include <bits/stdc++.h>
using namespace std;
const int N = 101;
short dp[N][N][N * N], a[N], ans;
int n;
short calc(int u, int k, int sum) {
  if (u == N) return !sum && !k;
  short &ref = dp[u][k][sum];
  if (ref != -1) return ref;
  ref = 0;
  for (short i = 0; i <= a[u] && sum - u * i >= 0 && i <= k; i++)
    ref += calc(u + 1, k - i, sum - u * i);
  return ref = min(ref, (short)2);
}
int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  int freq = 0;
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    if (!::a[a]) freq++;
    ::a[a]++;
  }
  for (short i = 1; i < N; i++)
    for (short j = 1; j <= a[i]; j++)
      if (calc(1, j, i * j) == 1) {
        ans = max(ans, j);
        if (j == a[i] && freq == 2) ans = n;
      }
  cout << ans << endl;
}
