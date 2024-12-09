#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)5e5 + 2;
const long long MOD = (long long)1e9 + 7;
const long long MOD1 = (long long)998244353;
const long long inf = (long long)1e18 + 6;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
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
long long bin_pow(long long x, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mult(x, bin_pow(x, p - 1));
  return bin_pow(mult(x, x), p / 2);
}
long long rev(long long x) { return bin_pow(x, MOD - 2); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  cout << fixed;
  long long n;
  cin >> n;
  string ans = "VIBGYOR";
  for (int i = 8; i <= n; i++) ans += ans[i - 5];
  cout << ans;
}
