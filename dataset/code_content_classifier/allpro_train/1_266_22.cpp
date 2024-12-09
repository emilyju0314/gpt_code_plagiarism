#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void solve() {
  long long n, mn = (long long)1e7;
  cin >> n;
  for (long long i = 1; i < sqrt(n) + 1; ++i)
    if (n % i == 0 && lcm(i, n / i) == n) mn = min(i, n / i);
  cout << mn << " " << n / mn;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
