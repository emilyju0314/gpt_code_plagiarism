#include <bits/stdc++.h>
using namespace std;
const int nmax = 100010;
const int mod = 1000000007;
int n, a[101], b[101], k, c[101];
bool u[101][2020];
int dp[101][2020];
int solve(int pos, int sum) {
  if (sum < -1000 || sum > 1000) return -mod;
  if (pos == 0) return sum == 0 ? 0 : -mod;
  if (u[pos][sum + 1000]) return dp[pos][sum + 1000];
  int ans = -mod;
  ans = max(ans, solve(pos - 1, sum + c[pos]) + a[pos]);
  ans = max(ans, solve(pos - 1, sum));
  u[pos][sum + 1000] = 1;
  return dp[pos][sum + 1000] = ans;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i] *= k;
    c[i] = a[i] - b[i];
  }
  int ans = solve(n, 0);
  cout << (ans == 0 ? -1 : ans) << endl;
  return 0;
}
