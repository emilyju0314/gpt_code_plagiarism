#include <bits/stdc++.h>
using namespace std;
int dp[1001][20001][2], n, a[1001];
int solve(int pos, int sum, bool op) {
  if (pos == n) {
    return 0;
  }
  int &ret = dp[pos][sum][op];
  if (ret != -1) return ret % 1000000007;
  if (op == 0) {
    ret = solve(pos + 1, 10000 + a[pos], 1);
    ret = (ret + solve(pos + 1, 10000 - a[pos], 1)) % 1000000007;
    ret = (ret + solve(pos + 1, 10000, 0)) % 1000000007;
    return ret % 1000000007;
  }
  int temp = sum + a[pos];
  int temp1 = sum - a[pos];
  ret = solve(pos + 1, temp1, 1);
  ret = (ret + solve(pos + 1, temp, 1)) % 1000000007;
  if (temp == 10000) {
    ret = (ret + 1) % 1000000007;
  }
  if (temp1 == 10000) {
    ret = (ret + 1) % 1000000007;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 10000, 0) << endl;
  return 0;
}
