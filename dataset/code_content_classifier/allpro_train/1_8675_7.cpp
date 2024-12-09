#include <bits/stdc++.h>
using namespace std;
const long long infl = 0x3f3f3f3f3f3f3f3fLL;
const long long infi = 0x3f3f3f3f;
const long long mod = 1000000007;
long long gcd(long long a, long long b);
long long pow(long long a, long long b);
void solve() {
  long long n;
  cin >> n;
  vector<long long> vec(n);
  for (auto &x : vec) cin >> x;
  for (long long i = 0; i < n; i++) {
    if (vec[i] < 0) vec[i] *= -1;
  }
  for (long long i = 0; i < n; i += 2) vec[i] *= -1;
  for (auto x : vec) cout << x << " ";
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  long long tt;
  tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
