#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> zalg(string s) {
  vector<int> z(s.size());
  for (int i = 1, L = 0, R = 0; i < s.size(); ++i) {
    if (R < i) {
      L = R = i;
      while (R < s.size() && s[R] == s[R - L]) R++;
      z[i] = R - L, R--;
    } else {
      if (z[i - L] < R - i + 1)
        z[i] = z[i - L];
      else {
        L = i;
        while (R < s.size() && s[R] == s[R - L]) R++;
        z[i] = R - L, R--;
      }
    }
  }
  return z;
}
int dp[1000005];
int dp_sum[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, l, r;
  cin >> a >> l >> r;
  vector<int> zl, zr;
  int n = a.size();
  zl = zalg(l + '$' + a);
  zr = zalg(r + '$' + a);
  dp[n] = dp_sum[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (n - i < l.size()) {
      dp[i] = 0;
    } else if (a[i] == '0') {
      if (l.size() == 1 && l[0] == '0') dp[i] = dp[i + 1];
    } else {
      int first_miss_l = zl[l.size() + 1 + i];
      int idx_l, idx_r;
      if (first_miss_l == l.size())
        idx_l = l.size() - 1;
      else
        idx_l = a[i + first_miss_l] > l[first_miss_l] ? l.size() - 1
                                                      : l.size() - 1 + 1;
      if (n - i >= r.size()) {
        int first_miss_r = zr[r.size() + 1 + i];
        if (first_miss_r == r.size())
          idx_r = r.size() - 1;
        else
          idx_r = a[i + first_miss_r] < r[first_miss_r] ? r.size() - 1
                                                        : r.size() - 2;
      } else {
        idx_r = n - i - 1;
      }
      dp[i] = sub(dp_sum[i + idx_l + 1], dp_sum[i + idx_r + 2]);
    }
    dp_sum[i] = add(dp[i], dp_sum[i + 1]);
  }
  cout << dp[0] << endl;
  return 0;
}
