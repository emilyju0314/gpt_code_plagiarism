#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long power(long long base, long long n) {
  if (n == 0) return 1;
  if (n == 1) return base;
  long long halfn = power(base, n / 2);
  if (n % 2 == 0)
    return (halfn * halfn) % M;
  else
    return (((halfn * halfn) % M) * base) % M;
}
void solve() {
  long long p, q;
  cin >> p >> q;
  if (p % q != 0) {
    cout << p << '\n';
    return;
  }
  vector<long long> v;
  long long z = sqrt(q), i;
  for (i = 2; i <= z; i++) {
    if (q % i == 0) {
      v.push_back(i);
      if (i != (q / i)) v.push_back(q / i);
    }
  }
  sort(v.begin(), v.end());
  v.push_back(q);
  long long x = p / q;
  long long ans = 1;
  for (long long i = v.size() - 1; i >= 0; i--) {
    long long an = 1, xx = x;
    while (xx % v[i] == 0) xx /= v[i];
    an = xx * (q / v[i]);
    if (an % q) ans = max(ans, an);
  }
  cout << ans << '\n';
}
int main() {
  fast();
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
