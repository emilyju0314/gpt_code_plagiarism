#include <bits/stdc++.h>
using namespace std;
long long pwmd(long long a, long long n) {
  if (!n) return 1;
  long long pt = pwmd(a, n / 2);
  pt *= pt, pt %= 998244353;
  if (n & 1) pt *= a, pt %= 998244353;
  return pt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    if (i == n) {
      cout << 10 << endl;
    } else {
      long long ans;
      ans = 10 * 9 * pwmd(10, n - i - 1) * 2;
      ans += 10 * 9 * 9 * (n - i - 1) * pwmd(10, n - i - 2);
      ans %= 998244353;
      cout << ans << " ";
    }
  }
  return 0;
}
