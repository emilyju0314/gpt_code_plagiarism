#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e5 + 10;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long n, k, a[mxn], fen[mxn][12], dp[mxn][12];
void add(long long l, long long k, long long val) {
  for (; l < mxn; l += l & -l) fen[l][k] += val;
}
long long sum(long long l, long long k) {
  long long res = 0;
  for (; l; l -= l & -l) res += fen[l][k];
  return res;
}
int main() {
  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    add(a[i], 1, 1);
    for (int j = 2; j <= k; j++) {
      dp[i][j] = sum(a[i] - 1, j - 1);
      add(a[i], j, dp[i][j]);
    }
  }
  long long num = 0;
  for (int i = 1; i <= n; i++) num += dp[i][k];
  cout << num << endl;
  return 0;
}
