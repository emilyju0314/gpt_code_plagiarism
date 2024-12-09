#include <bits/stdc++.h>
using namespace std;
long long dp[300][300][300];
long long data[(int)2e5];
long long n, k;
long long func(int h, long long l, long long u) {
  if (h == 0 and l + k > n) {
    return 0;
  } else if (h == 0)
    return -1e17;
  if (l == n) return -1e17;
  if (dp[h][l][u]) return dp[h][l][u];
  long long ans = -1e17;
  for (int i = l; i <= u and i < n; i++) {
    if (u == i)
      ans = max(ans, data[i] + func(h - 1, i + 1, u + k));
    else
      ans =
          max(ans, max(func(h, i + 1, u), data[i] + func(h - 1, i + 1, i + k)));
  }
  return dp[h][l][u] = ans;
}
int main() {
  int x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) cin >> data[i];
  long long b = func(x, 0, k - 1);
  if (b < 0)
    cout << -1;
  else
    cout << b;
  return 0;
}
