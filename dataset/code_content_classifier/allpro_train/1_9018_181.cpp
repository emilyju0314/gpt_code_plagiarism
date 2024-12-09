#include <bits/stdc++.h>
using namespace std;
long long dp[32][2][2][2][2];
vector<long long> a, b;
long long solve(long long idx, long long f1, long long f2, long long f3,
                long long f4) {
  if (idx == 32) return 1;
  if (dp[idx][f1][f2][f3][f4] != -1) return dp[idx][f1][f2][f3][f4];
  long long l1, r1, l2, r2;
  if (f2 == 1)
    r1 = b[idx];
  else
    r1 = 1;
  if (f1 == 1)
    l1 = a[idx];
  else
    l1 = 0;
  if (f4 == 1)
    r2 = b[idx];
  else
    r2 = 1;
  if (f3 == 1)
    l2 = a[idx];
  else
    l2 = 0;
  if (l1 > r1 || l2 > r2) {
    dp[idx][f1][f2][f3][f4] = 0;
    return 0;
  }
  long long ans = 0;
  for (int i = l1; i <= r1; ++i) {
    for (int j = l2; j <= r2; ++j) {
      if ((i ^ j) == (i + j)) {
        long long nf1, nf2, nf3, nf4;
        if (f2 == 1) {
          if (i < b[idx])
            nf2 = 0;
          else
            nf2 = 1;
        } else
          nf2 = 0;
        if (f1 == 1) {
          if (i > a[idx])
            nf1 = 0;
          else
            nf1 = 1;
        } else
          nf1 = 0;
        if (f4 == 1) {
          if (j < b[idx])
            nf4 = 0;
          else
            nf4 = 1;
        } else
          nf4 = 0;
        if (f3 == 1) {
          if (j > a[idx])
            nf3 = 0;
          else
            nf3 = 1;
        } else
          nf3 = 0;
        ans += solve(idx + 1, nf1, nf2, nf3, nf4);
      }
    }
  }
  dp[idx][f1][f2][f3][f4] = ans;
  return ans;
}
int main(int argc, char const *argv[]) {
  long long t;
  cin >> t;
  while (t--) {
    a.clear();
    b.clear();
    memset(dp, -1, sizeof(dp));
    long long num;
    cin >> num;
    while (num) {
      a.push_back(num & 1);
      num >>= 1;
    }
    cin >> num;
    while (num) {
      b.push_back(num & 1);
      num >>= 1;
    }
    while (a.size() < 32) a.push_back(0);
    while (b.size() < 32) b.push_back(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long ans = solve(0, 1, 1, 1, 1);
    cout << ans << '\n';
  }
  return 0;
}
