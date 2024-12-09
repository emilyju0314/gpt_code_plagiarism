#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long int power(long long int a, long long int b,
                    long long int m = 1000000007) {
  long long int ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1LL * a * ans) % m;
    b >>= 1;
    a = (1LL * a * a) % m;
  }
  return ans;
}
long long int ncr(long long int n, long long int r) {
  long long int res = 1;
  if (r > n - r) r = n - r;
  for (long long int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "******************\nTime taken : "
       << (long double)(time_p) / CLOCKS_PER_SEC << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  long long int ii = 0;
  while (tt-- && ++ii) {
    long double h, c, t;
    cin >> h >> c >> t;
    long double temp = (h + c) / 2;
    if (t <= temp) {
      cout << 2 << "\n";
      continue;
    }
    long double val = (c - t) / (h + c - t - t);
    long long int d = val;
    long long int u = val + 1;
    long double uu = (h * u + (u - 1) * c) / (2 * u - 1);
    long double dd = (h * d + (d - 1) * c) / (2 * d - 1);
    if (abs(t - dd) <= abs(t - uu))
      cout << 2 * d - 1 << "\n";
    else
      cout << 2 * u - 1 << "\n";
  }
  rtime();
  return 0;
}
