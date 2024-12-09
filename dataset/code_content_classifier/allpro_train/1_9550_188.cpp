#include <bits/stdc++.h>
using namespace std;
long long T, TT = 1, mod = (long long)(1e9 + 7), a[1000005], b[1000005],
             c[1000005], fq[1000005] = {0}, ali = LLONG_MAX;
long long dp[201][201][201];
void file() {}
long long power(long long x, long long y, long long p = ali) {
  x = x % p;
  long long res = 1;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    x = (x * x) % p;
    y = y >> 1;
  }
  return res;
}
void solve_testcase() {
  long long n, i, m, x, y, j = 0, q, k = 0, ans = 0;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  k = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] < k) {
      x = k - a[i];
      if (x >= j) {
        ans += (x - j);
      }
      j = x;
    } else {
      k = a[i];
      j = 0;
    }
  }
  cout << ans;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  file();
  cin >> TT;
  for (T = 1; T <= TT; T++) {
    solve_testcase();
  }
  return 0;
}
